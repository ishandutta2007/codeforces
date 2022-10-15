#ifndef CPL_TEMPLATE
#define CPL_TEMPLATE
/*
	Normie's Template v2.5
	Changes:
    Added warning against using pragmas on USACO.
*/
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;

//Pragmas (Comment out these three lines if you're submitting in szkopul or USACO.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0)
#define nfio cin.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
// template<typename T>
// __attribute__((always_inline)) void chkmin(T& a, const T& b) {
//     a=(a<b)?a:b;
// }

// template<typename T>
// __attribute__((always_inline)) void chkmax(T& a, const T& b) {
//     a=(a>b)?a:b;
// }
 
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
#endif

namespace CPL_DinicMaxFlow
{
// Normie's implementation of Dinic max flow.
// NOTE: if you need to work with numbers > 1e9, change int_t from int to ll and MAXINT to 1e18+7
const int MAXN=1101; // maximum number of vertices you will be using
const int MAXINT=1000000007;
template <class int_t> //int_t should be an intergral type
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

template <class int_t>
struct dinic_graph
// Structure to reppresent a directed flow graph.
{
	private:
	
	vector<edge<int_t>> lis;                          // List of edges in graph.
	vector<edge<int_t>> lis_t;                        // A copy of lis, for use with the algorithms.
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
	
	vector<pii(int)> debug() // just some debugging
	{
		vector<pii(int)> res;
	    for (int_t i=0;i<lis_t.size();i++)
	    {
			if (lis_t[i].u<lis_t[i].v && !lis_t[i].cap) {
				res.push_back({lis_t[i].u,lis_t[i].v});
			}
		}
		return res;

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
}
using namespace CPL_DinicMaxFlow;
dinic_graph<int> gr(1010);

vector<int> vl;
vector<int> vr;
int n,m,i,j,k,t,t1,u,v,a,b;
int used[1001];
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++) {
		cin>>u;
		if (u<=m/3) vr.push_back(u);
		else vl.push_back(u);
	}
	for (i=0;i<vl.size();i++) gr.add_edge(n,i,1);
	for (i=0;i<vr.size();i++) gr.add_edge(i+vl.size(),n+1,1);
	for (i=0;i<vl.size();i++) for (j=0;j<vr.size();j++) {
		if (vl[i]%vr[j]==0 && (m-vr[j])/2>=vl[i]) {
			gr.add_edge(i,j+vl.size(),1);
		}
	}
	if (gr.calc_flow(n,n+1)!=vl.size()) {
		cout<<-1;
	}
	else {
		auto sus = gr.debug();
		vector<pii(int)> fin;
		for (auto g : sus) if (g.fi!=n && g.se!=n+1) {
			// cout<<g.fi<<' '<<g.se<<endl;
			fin.push_back({2*vl[g.fi]+vr[g.se-vl.size()],vl[g.fi]+vr[g.se-vl.size()]});
			used[g.se-vl.size()]=1;
		}
		for (i=0;i<vr.size();i++) if (!used[i]) {
			fin.push_back({vr[i]*3,vr[i]*2});
		}
		cout<<fin.size()<<endl;
		for (auto g : fin) cout<<g.fi<<' '<<g.se<<endl;
	}
}
// a;