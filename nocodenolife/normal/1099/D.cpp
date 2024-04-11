#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define ForA1(n)  for (ll i=0; i<n; i++)
#define ForA2(n)  for (ll j=0; j<n; j++)
#define ForA3(n)  for (ll k=0; k<n; k++)
#define ForN1(n)  for (ll i=1; i<=n; i++)
#define ForN2(n)  for (ll j=1; j<=n; j++)
#define ForN3(n)  for (ll k=1; k<=n; k++)

#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define F first
#define S second
#define debug(x)    cerr << #x << " = " << x << endl;
#define mem(x) memset(x,0,sizeof(x))
#define PI 3.1415926535897932384626433832795l
#define deci(n) cout<<fixed<<setprecision(n);


using namespace std;

ll a[100005];
ll s[100005];
ll flag;

class Graph 
{ 
    ll V;    // No. of vertices 
  
    // Pointer to an array containing 
    // adjacency lists 
    list<ll> *adj; 
  
    // A recursive function used by DFS 
    void DFSUtil(ll v, bool visited[], ll par); 
public: 
    Graph(ll V);   // Constructor 
  
    // function to add an edge to graph 
    void addEdge(ll v, ll w); 
  
    // DFS traversal of the vertices 
    // reachable from v 
    void DFS(); 
}; 
  
Graph::Graph(ll V) 
{ 
    this->V = V; 
    adj = new list<ll>[V]; 
} 
  
void Graph::addEdge(ll v, ll w) 
{ 
    adj[v].push_back(w);
    adj[w].push_back(v); // Add w to vs list. 
} 
  
void Graph::DFSUtil(ll v, bool visited[], ll par) 
{ 
    visited[v] = true; 
    // cout << v << " ";

    list<ll>::iterator i; 

    if(s[v]==-1)
    {
    	ll min = 1000000000000;
    	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    	{
        	if (!visited[*i]) 
        	{
            	if(s[*i]<min)
            		min = s[*i]; 
        	}
        }
        if(min==1000000000000)
        {
        	s[v]=s[par];
        }
        else
        {
        	s[v] = min;
        }

    }
    
    a[v] = s[v] - s[par];
    if(a[v]<0)
   		flag = 1;
    

    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    {
        if (!visited[*i]) 
            DFSUtil(*i, visited, v); 
    }
} 
  
void Graph::DFS() 
{ 
    bool *visited = new bool[V]; 
    for (ll i = 0; i < V; i++) 
        visited[i] = false; 
    visited[0] = true;
    list<ll>::iterator i; 
  	for (i = adj[0].begin(); i != adj[0].end(); ++i) 
    {
        if (!visited[*i]) 
            DFSUtil(*i, visited, 0); 
    }
} 

int main()
{
	#ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
	    freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,temp;
    cin>>n;
    flag = 0;
    Graph g(n);
    ForN1(n-1)
    {
    	cin>>temp;
    	temp--;
    	g.addEdge(i,temp);
    }

    ForA1(n)
    {
    	cin>>s[i];
    }
    a[0] = s[0];

    g.DFS();

    if(flag)
    {
    	cout<<-1<<endl;
    	return 0;
    }

    ll ans = 0;
    ForA1(n)
    {
    	ans+=a[i];
    	// cout<<a[i]<<" ";
    }
    cout<<ans<<endl;

    return 0;
}