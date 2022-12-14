/*
        Normie's Template v2.0
*/

// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;

// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)

//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"

//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))

//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320

//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>

//Quick power of 2.
#define pow2(x) (ll(1)<<x)

//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)

//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
// Normie's implementation of Dinic max flow.
// NOTE: if you need to work with numbers > 1e9, change int_t from int to ll and MAXINT to 1e18+7
#define MAXN 110001 // maximum number of vertices you will be using
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
	
};
dinic_graph gr(100001);
int mp[211][211];
int valid[211][211][2];
int n,m,i,j,k,t,t1,cntsq,cnte;
char c;
int convert (int i, int j, int k)
{
	return (i-1)*(m+1)*2+(j-1)*2+k+1;
}
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++)
	{
		char c;
		cin>>c;
		mp[i][j]=(c=='#');
		cntsq+=mp[i][j];
	}
	for (i=1;i<=n+1;i++) for (j=1;j<=m+1;j++)
	{
			valid[i][j][0]=((mp[i-1][j])and(mp[i][j]));
			valid[i][j][1]=((mp[i][j-1])and(mp[i][j]));
	}
	for (i=1;i<=n+1;i++) for (j=1;j<=m+1;j++)
	{
		if (valid[i][j][0])
		{
			cnte++;
			gr.add_edge(0,convert(i,j,0),1);
			if (valid[i][j][1])
			{
			gr.add_edge(convert(i,j,0),convert(i,j,1),1000000);
			}
			if (valid[i][j+1][1])
			{
			gr.add_edge(convert(i,j,0),convert(i,j+1,1),1000000);
			}
			if (valid[i-1][j][1])
			{
			gr.add_edge(convert(i,j,0),convert(i-1,j,1),1000000);
			}
			if (valid[i-1][j+1][1])
			{
			gr.add_edge(convert(i,j,0),convert(i-1,j+1,1),1000000);
			}
		}
		if (valid[i][j][1])
		{
			cnte++;
			gr.add_edge(convert(i,j,1),(m+1)*(n+1)*2+1,1);
		}
	}
	cout<<cntsq-(cnte-gr.calc_flow(0,(m+1)*(n+1)*2+1));
}