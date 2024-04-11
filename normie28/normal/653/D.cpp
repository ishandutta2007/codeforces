/*
khoi orz, go check out his algo
-normie-
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "birds.inp"
#define FILE_OUT "birds.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
#define ll long long
#define pi 3.1415926535897
//------START-----------//
// Normie's implementation of Dinic max flow.
// NOTE: if you need to work with numbers > 1e9, change int_t from int to ll and MAXINT to 1e18+7
#define MAXN 1101 // maximum number of vertices you will be using
#define int_t int
#define MAXINT 1000000007
struct edge
// Structure to represent a directed graph edge.
// u  : outgoing vertex
// v  : incoming vertex
// cap: remaining capacity of vertex
// rev: This edge's reverse edge id.
{
	int_t u,v,cap,rev;
	edge(int_t uu, int_t vv, int_t revv, int_t capp=0) // constructor
	{
		u=uu;
		v=vv;
		rev=revv;
		cap=capp;	
	} 
};
struct dinic_graph
// Structure to reppresent a directed flow graph.
{
	private:
	
	vector<edge> lis;                          // List of edges in graph.
	vector<edge> lis_t;                        // A copy of lis, for use with the algorithms.
	vector<int_t> adj[MAXN];                   // Adjacency list for each vertex. Edges are identified by their id as stored in [lis]
	vector<int_t> layer_adj[MAXN];             // Adjacency list in layer graph, for use with the algorithms
	int_t n;                                   // Actual number of vertices.
	int_t s,t;                                 // Source and sink of graph.
	int_t res;                                 // The current result, for use with the algorithms.
	int_t dis[MAXN];                           // The distance between vertices and s, for use with the algorithms.
	int_t ptr[MAXN];                           // Pointer of current non-zero edge from a vertex, for use with DFS.
	deque<int_t> bruh;                         // Queue for bfs to use 
	vector<int_t> least;                       // Vector of edges with least capacity in graph, for use with DFS.
	
	void proc(int_t cur)                       // Relaxes a vertex.
	{
		for (int_t g: adj[cur])
		{
			// Positive capacity and not visited yet
			if ((lis_t[g].cap)and(dis[lis_t[g].v]==MAXINT)) 
			{
				// Relaxes along this edge
				dis[lis_t[g].v]=dis[cur]+1;
				bruh.push_back(lis_t[g].v);
			}
		}
	}
	
	void build_layer()                         // Builds the layer graph for the Dinic algo to use
	{
		for (int_t i=0;i<n;i++) dis[i]=MAXINT;
		// Initializes the bfs.
		dis[s]=0;
		bruh.push_back(s);
		while(bruh.size())
		{
			proc(bruh.front()) ;                // Processes the vertex with lowest distance,
			bruh.pop_front();                   // then removes it from queue.
		}
		// Creates layer graph adjacency list with eligible edges
		for (int_t i=0;i<n;i++)
		layer_adj[i].clear();                  // Resets adjacency list
		for (int_t i=0;i<lis_t.size();i++)
		{
			if (dis[lis_t[i].v]-dis[lis_t[i].u]==1)
			{
				layer_adj[lis_t[i].u].push_back(i); 
			} 
		}
	}
	
	// DFS possible blocking flows.
	// cur: current vertex.
	// siz: Maximum flow value of current blocking flow at vertex cur.
	int_t dfs(int_t cur, int_t siz)
	{
		if (siz==0) return 0;                  // We hit an empty edge.
		if (cur==t) return siz;                // We hit the sink.
		for (ptr[cur]=ptr[cur];ptr[cur]<layer_adj[cur].size();ptr[cur]++) // Traverse the edges until we find a suitable next edge
		{
			int_t edgeid=layer_adj[cur][ptr[cur]];               // current edge id
			if (!lis_t[edgeid].cap) continue;  // Empty edge.
			int_t attempt=dfs(lis_t[edgeid].v, 
			min(siz,lis_t[edgeid].cap));       // Attempt to find flow down this edge.
			if (!attempt) continue;                              // Attempt failed.
			lis_t[edgeid].cap-=attempt;        // Attempt succeed, update the edges with the flow value and return it.
			lis_t[lis_t[edgeid].rev].cap+=attempt;
			return attempt;
		}
		// No more edges to traverse -> this vertex is unusable
		return 0;
	}
	
	public:
	
	void debug() // just some debugging
	{
	    cout<<n<<' '<<s<<' '<<t<<endl;
	    for (int_t i=0;i<lis_t.size();i++)
	    {
	    	cout<<i<<' '<<lis_t[i].u<<' '<<lis_t[i].v<<' '<<lis_t[i].cap<<' '<<lis_t[i].rev<<endl;
		}
		for (int_t i=0;i<n;i++)
		{
			cout<<i<<' ';
			for (int_t g: adj[i]) cout<<g<<' ';
			cout<<endl;
		}
		for (int_t i=0;i<n;i++)
		{
			cout<<i<<' ';
			for (int_t g: layer_adj[i]) cout<<g<<' ';
			cout<<endl;
		}
		for (int_t i=0;i<n;i++) cout<<dis[i]<<' '; cout<<endl;
	}
	
	dinic_graph(int_t nn=1)                    // Constructor
	{
		n=nn;
	}
	
	void add_edge(int_t u, int_t v, int_t cap) // Adds an edge to the graph, as well as its residual edge.
	{
		int_t id=lis.size()-1;
		lis.push_back(edge(u,v,id+2,cap));     // Adds edge to lis
		adj[u].push_back(id+1);                // Adds newly created edge's id to u's adjacency list
		lis.push_back(edge(v,u,id+1));         // Same with residual edge
		adj[v].push_back(id+2);
	}
	
	int_t calc_flow(int_t ss, int_t tt)        // Calculate the maximum flow
	{
		// Some initialization stuff.
		s=ss; t=tt;
		res=0;
		int_t cycle=0;
		lis_t=lis;
		while (true)                           // Loops the algorithm until there's no more blocking flows.
		{
		    cycle++;
		build_layer();                         // Builds layer graph.
		
		if (dis[t]==MAXINT)
		{
			return res;                        // No more blocking flows, which means that we now have the max flow, so we quit. sed
		}
		for (int_t i=0;i<n;i++) ptr[i]=0;      // Reset pointers.
		while(int_t pushed=dfs(s,MAXINT))
		{
		res+=pushed;                           // DFS and add all blocking flows to result.
		}
		}
	}
	
	pair<int_t,vector<edge>> detailed_calc_flow(int_t ss, int_t tt)        // Calculate the maximum flow, with additional detail of flows for each edge
	{
		// Some initialization stuff.
		s=ss; t=tt;
		res=0;
		int_t cycle=0;
		lis_t=lis;
		while (true)                           // Loops the algorithm until there's no more blocking flows.
		{
		    cycle++;
		build_layer();                         // Builds layer graph.
		
		if (dis[t]==MAXINT)
		{
			return {res,lis_t};
		}
		for (int_t i=0;i<n;i++) ptr[i]=0;      // Reset pointers.
		while(int_t pushed=dfs(s,MAXINT))
		{
		res+=pushed;                           // DFS and add all blocking flows to result.
		}
		}
	}
};
//------END-----------//
ll n,m,k,c[501],t,t1,i,j,res,res2;
vector<piii> e;
double bs (double l, double r)
{
	if ((r-l)*k<double(1)/10000000) return l;
	double mid=(l+r)/2;
	dinic_graph gr(n+1);
	{
		for (piii g:e)
		{
			gr.add_edge(g.p1,g.p2,int(floor(double(g.p3)/mid)));
		}
		if (gr.calc_flow(1,n)>=k) return bs(mid,r); else return bs(l,mid);
	}
}
int main()
{
//    ofile;
    fio;
    cin>>n>>m>>k;
    for (i=0;i<m;i++)
    {
    	int a,b,c;
    	cin>>a>>b>>c;
    	e.push_back({a,{b,c}});
	}
	cout<<fixed<<setprecision(9)<<bs(double(1)/k,1e6)*k;
}