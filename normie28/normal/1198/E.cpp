// Problem: E. Rectangle Painting 2
// Contest: Codeforces - Codeforces Round #576 (Div. 1)
// URL: https://codeforces.com/contest/1198/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
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
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
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

// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
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
//	    cout<<n<<' '<<s<<' '<<t<<endl;
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
	//	cout<<u<<' '<<v<<' '<<cap<<endl;
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
dinic_graph gr(220);


vector<ll> vecx,vecy;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll x1[51],x2[51],y1[51],y2[51];
ll inn[101][101];
int main()
{
	fio;
	cin>>n>>m;
	if (!m) return cout<<0,0;
	for (i=1;i<=m;i++)
	{
		cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
		x2[i]++;
		y2[i]++;
		
	vecx.push_back(x1[i]);
	vecx.push_back(x2[i]);
	vecy.push_back(y1[i]);
	vecy.push_back(y2[i]);
	}
	sort(vecx.begin(),vecx.end());
	auto itx=unique(vecx.begin(),vecx.end());
	vecx.erase(itx,vecx.end());
	
	sort(vecy.begin(),vecy.end());
	auto ity=unique(vecy.begin(),vecy.end());
	vecy.erase(ity,vecy.end());
	for (i=1;i<=m;i++)
	{
		x1[i]=lower_bound(vecx.begin(),vecx.end(),x1[i])-vecx.begin();
		x2[i]=lower_bound(vecx.begin(),vecx.end(),x2[i])-vecx.begin();
		y2[i]=lower_bound(vecy.begin(),vecy.end(),y2[i])-vecy.begin();
		y1[i]=lower_bound(vecy.begin(),vecy.end(),y1[i])-vecy.begin();
		for (j=x1[i];j<x2[i];j++) for (k=y1[i];k<y2[i];k++) inn[j][k]=1;
	}
	a=vecx.size()-1;b=vecy.size()-1;
//	for (auto g : vecx) cout<<g<<' '; cout<<endl;
	//for (auto g : vecy) cout<<g<<' '; cout<<endl;
	for (i=0;i<a;i++) for (j=0;j<b;j++) if (inn[i][j])
	{
		gr.add_edge(i,a+j,1e9);
	}
	for (i=0;i<a;i++) gr.add_edge(a+b,i,vecx[i+1]-vecx[i]);
	for (i=0;i<b;i++) gr.add_edge(i+a,a+b+1,vecy[i+1]-vecy[i]);
	cout<<gr.calc_flow(a+b,a+b+1);
}