// author - Saksham :)
#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp> 
//using namespace boost::multiprecision;
#define ll long long int
#define ld long double
#define bigint int64_t
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test ll t;read(t);while(t--)
#define all(v) v.begin(),v.end()

#define forn(i,n) for(ll (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(ll (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(ll (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b,c) for(ll (i) = a ; (i) <= (b) ; (i)+=(c))

using namespace std;

template <typename T>
void read(T &x){
	cin >> x;
}
template <typename T , typename T0>
void read(T &x,T0 &y){
	cin >> x >> y;
}

template <typename T , typename T0 , typename T1>
void read(T &x,T0 &y,T1 &z){
	cin >> x >> y >> z;
}

template <typename T , typename T0 , typename T1 , typename T2>
void read(T &x,T0 &y,T1 &z,T2 &w){
	cin >> x >> y >> z >> w;
}

template <typename T , typename T0>
void read(pair< T , T0 > &p){
	cin >> p.fst >>p.scd;
}

template <typename T>
void read(vector< T > &oneD){
	for(ll i=0;i<oneD.size();i++){
		read(oneD[i]);
	}
}

template <typename T>
void read(T oneD[] , ll n){
	for(ll i=0;i<n;i++){
		read(oneD[i]);
	}
}

template <typename T>
void write(T &x){
	
	cout << x << " ";
}

template <typename T , typename T0>
void write(T &x,T0 &y){
	cout << x << " " << y << "\n";
}

template <typename T , typename T0 , typename T1>
void write(T &x,T0 &y,T1 &z){
	cout << x << " " << y << " " << z << "\n";
}

template <typename T , typename T0 , typename T1 , typename T2>
void write(T &x,T0 &y,T1 &z,T2 &w){
	cout << x << " " << y << " " << z << " " << w << "\n";
}

template <typename T , typename T0>
void write(pair< T , T0 > &p){
	write(p.fst);
	write(p.scd);
	cout << endl;
}

template <typename T>
void write(vector< T > &oneD){
	for(ll i=0;i<oneD.size();i++){
		write(oneD[i]);
	}
	cout << endl;
}

template <typename T>
void write(T oneD[] ,int n){
	for(ll i=0;i<n;i++){
		write(oneD[i]);
	}
	cout << endl;
}

template <typename T , typename T0>
void write(map< T , T0 > &mpp){
	for(auto it : mpp){
		write(it.fst);
		cout << ": ";
		write(it.scd);
		cout << "\n";
	}
	cout<<endl;
}

string getString(char x) 
{ 
    string s(1, x); 
    return s;    
} 

ll getnumber(string x)
{
	if(x=="")
	return 0;
	ll ans = 0;
	ll count = 0;
	forr(i,x.length())
	{
		ll y = x[i]-'0';
		ans+=(y*pow(10,count));
		count++;
	}
	return ans;
}

template<typename T>
class Graph
{
    map<ll,vll> m;
    public:
    Graph()
    {

    }
	bool nodecheck(T u,T v)
	{
		for(auto x:m[u])
		{
			if(v==x)
			return true;
		}
		return false;
	}
    void addedge(T u,T v)
    {
        m[u].pb(v);
    }
	void topoHelper(T node,map<T,bool> &vi,list<T> &ans)
    {
        //cout<<node<<" ";
        vi[node]=true;
        for(auto x:m[node])
        {
            if(!vi[x])
            topoHelper(x,vi,ans);
        }
        ans.push_front(node);
    }
    void topological(ll n,ofstream &outfile)
    {
		outfile<<"Topological Order = \n";
        map<T,bool> vi;
        list<T> ans;
        forn(i,n)
        {
            vi[i]=false;
        }
        forn(i,n)
        {
            if(!vi[i])
            {
                topoHelper(i,vi,ans);
            }
        }
        for(auto x:ans)
        {
            outfile<<(x+1)<<" ";
        }
    }
	bool CyclicHelper(T node,map<T,bool> &visited,map<T,bool> &instack)
    {
        visited[node]=true;
        instack[node]=true;
        for(auto x:m[node])
        {
            if(!visited[x]&&CyclicHelper(x,visited,instack)||instack[x])
            {
                return true;
            }
        }
        instack[node]=false;
        return false;
    }
    bool isCyclic(ll n)
    {
        map<T,bool> visited;
        map<T,bool> instack;
        forn(i,n)
        {
            visited[i]=false;
            instack[i]=false;
        }
        for(auto x:m)
        {
            if(!visited[x.first])
            {
                bool ans = CyclicHelper(x.first,visited,instack);
                if(ans)
                return true;
            }
        }
        return false;
    }
	void connected_component(T src,vector<bool> &vis)
    {
        queue<T> q;
        q.push(src);
        vis[src]=true;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            // You may simply display node to print bfs order
            for(auto x:m[node])
            {
                if(!vis[x])
                {
                    q.push(x);
                    vis[x]=true;
                }
            }
        }
    }
	void dfsHelper(T node,map<T,bool> &visited,vll &en,vll &ex,ll &t)
    {
        en[node]=t++;
        //cout<<node<<" ";
        visited[node]=true;
        for(auto x:m[node])
        {
            if(!visited[x])
            dfsHelper(x,visited,en,ex,t);
        }
        ex[node]=t++;
    }
    void dfs(T src,ll n,vll &en,vll &ex,map<T,bool> &visited,ll &t)
    {
        dfsHelper(src,visited,en,ex,t);
    }
    void bfs(T src,ll n,ofstream &outfile,vector<bool> &visit)
    {
        queue<T> q;
        vll d(n);
        vector<T> p(n);
        q.push(src);
        p[src]=-1;
        d[src]=0;
        visit[src]=true;
		outfile<<"BFS ORDER = \n";
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            outfile<<(node+1)<<" "<<d[node]<<"\n";
            for(auto x:m[node])
            {
                if(!visit[x])
                {
                    q.push(x);
                    d[x]=d[node]+1;
                    p[x]=node;
                    visit[x]=true;
                }
            }
        }
    }
};

int main()
{
	Graph<ll> g;
	cout<<"Enter the name of input file(with extension) = \n";
	string s;
	read(s);
	ifstream file(s);
	ofstream outfile;
    outfile.open("output.txt");
	ll edges = 0;
    if(file.is_open()) {
    string line;
    while (getline(file, line)) {
		string a="";
		ll count = 0;
		ll u=0,v=0;
        forn(i,line.length())
		{
			if(line[i]!=' ')
			{
				a+=getString(line[i]);
			}
			else
			{
				count++;
				if(count==1){
				u=getnumber(a);
				edges++;}
				else
				{
					v=getnumber(a);
					if(v!=0){
					g.addedge(u-1,v-1);
					}
				}
				a="";
			}
		}
		if(count==0)
		edges++;
		v = getnumber(a);
		if(v!=0){
		g.addedge(u-1,v-1);
		}
    }
	cout<<"Enter your choice = \n";
	cout<<"1. BFS Order\n";
	cout<<"2. DFS Order\n";
	cout<<"3. Topological Order\n";
	cout<<"4. Connected Graph Check and detect Cycle\n";
	cout<<"5. Is Topological Sorted\n";
	ll dis;
	cin>>dis;
	vector<bool> visit(edges,false);
	if(dis==1)
	{
	g.bfs(0,edges,outfile,visit);
	ll check = 0;
	forn(i,edges)
	{
		if(!visit[i])
		{
			check++;
		}
	}
	if(check!=0)
	{
	outfile<<"Rest all not connected edges in BFS order = \n";
	forn(i,edges)
	{
		if(!visit[i])
		{
			outfile<<(i+1)<<" "<<"infinity\n";
		}
	}
	}
	}
	else if(dis==2)
	{
	outfile<<"DFS Order = \n";
	vll en(edges,0);
    vll ex(edges,0);
	map<ll,bool> visited;
	set<pair<ll,pair<ll,ll>>> answer;
    forn(i,edges)
    {
        visited[i]=false;
    }
    ll t = 0;
	forn(i,edges)
	{
	if(!visited[i])
	g.dfs(i,edges,en,ex,visited,t);
	}
	forn(i,edges)
	{
		answer.insert({(en[i]+1),{i+1,(ex[i]+1)}});
	}
	for(auto x:answer)
	{
		outfile<<x.second.first<<" "<<x.first<<" "<<x.second.second<<"\n";
	}
	}
	else if(dis==3)
	{
	g.topological(edges,outfile);
	}
	else if(dis==4)
	{
	vector<bool> vis(edges,false);
	ll ans = 0;
	forn(i,edges)
	{
		if(!visit[i])
		{
			g.connected_component(i,vis);
			ans++;
		}
	}
	outfile<<"\n";
	if(ans>=2)
	outfile<<"Not Connected Graph.\n";
	else
	{
		outfile<<"Connected Graph.\n";
	}
	bool cycle = g.isCyclic(edges);
	if(cycle)
	outfile<<"Cyclic.\n";
	else
	{
		outfile<<"Not Cyclic.\n";
	}
	file.close();
	}
	else if(dis==5)
	{
	// Input sequence of vertex
	ifstream file1(s);
	// This input file will contain sequence of vertex
	vll arr;
	if(file1.is_open()) {
    string line;
    while (getline(file1, line)) {
	ll u = 0;
	string a = "";
	forn(i,line.length())
	{
		if(line[i]!=' ')
		{
			a+=getString(line[i]);
		}
		else
		{
			u = getnumber(a);
			arr.push_back(u-1);
			a="";	
		}
	}
	}
	ll counter = 0;
	forn(i,arr.size()-1)
	{
		bool y = g.nodecheck(arr[i],arr[i+1]);
		if(y)
		counter++;
	}
	if(counter==(arr.size()-1))
	outfile<<"Topological Sorted\n";
	else
	{
		outfile<<"Not Topological Sorted\n";
	}
	file1.close();
	}
	else
	{
		outfile<<"Wrong choice\n";
	}
	outfile.close();
	}
	}
	return 0;
}
