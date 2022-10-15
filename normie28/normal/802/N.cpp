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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
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
#endif

// Normie's implementation of Dinic max flow.
// NOTE: if you need to work with numbers > 1e9, change int_t from int to ll and MAXINT to 1e18+7
#define MAXN 4411 // maximum number of vertices you will be using
#define int_t ll
#define MAXINT 1000000000000007
struct edge
// Structure to represent a directed graph edge.
// u  : outgoing vertex
// v  : incoming vertex
// cap: remaining capacity of vertex
// rev: This edge's reverse edge id.
{
	int_t u,v,cap,rev,cost;
	edge(int_t uu, int_t vv, int_t revv, int_t capp=0, int_t costt=0) // constructor
	{
		u=uu;
		v=vv;
		rev=revv;
		cap=capp;	
		cost=costt;
	} 
};
struct mcmf_graph
// Structure to reppresent a directed flow graph.
{
	private:
	
	vector<edge> lis;                          // List of edges in graph.
	vector<edge> lis_t;                        // A copy of lis, for use with the algorithms.
	vector<int_t> adj[MAXN];                   // Adjacency list for each vertex. Edges are identified by their id as stored in [lis]
	
	
	int_t n;                                   // Actual number of vertices.
	int_t s,t;                                 // Source and sink of graph.
	int_t res;                                 // The current result, for use with the algorithms.
	int_t resc;
	int_t nxt[MAXN],dis[MAXN],inq[MAXN],cnt[MAXN];
	
	vector<int_t> spfa()
	{
	deque<int_t> to_relax;
	    to_relax.push_back(s);
	    for (int_t i=0;i<n;i++)
	    {
	        nxt[i]=-1;
	        dis[i]=MAXINT;
	        inq[i]=0;
	        cnt[i]=0;
	    }
	    to_relax.push_back(s);
	    dis[s]=0;
	    inq[s]=1;
	    cnt[s]++;
	    while(to_relax.size())
	    {
	        int_t cur=to_relax.front();
	//        cout<<"relaxing "<<cur<<' '<<dis[cur]<<endl;
	        for (int_t g : adj[cur])
	        {
	            if ((dis[cur]+lis_t[g].cost<dis[lis_t[g].v])and(lis_t[g].cap))
	            {
	                dis[lis_t[g].v]=dis[cur]+lis_t[g].cost;
	                nxt[lis_t[g].v]=g;
	                if (!inq[lis_t[g].v])
	                {
	                    inq[lis_t[g].v]=1;
	                    cnt[lis_t[g].v]++;
	                    if (cnt[lis_t[g].v]>n) break;
	                
	                    to_relax.push_back(lis_t[g].v);
	                    
	                }
	            }
	        }
	        to_relax.pop_front();
	        inq[cur]=0;
	    }
	    int_t curn=t;
	    vector<int_t> ress;
	    while(curn!=s)
	    {
	        ress.push_back(nxt[curn]);
	        curn=lis_t[nxt[curn]].u;
	    }
	    return ress;
	    
	}
	public:
	
	void debug() // just some debugging
	{
	    cout<<n<<' '<<s<<' '<<t<<endl;
	    for (int_t i=0;i<lis.size();i++)
	    {
	    	cout<<i<<' '<<lis[i].u<<' '<<lis[i].v<<' '<<lis[i].cap<<' '<<lis[i].rev<<' '<<lis[i].cost<<endl;
		}
		for (int_t i=0;i<n;i++)
		{
			cout<<i<<' ';
			for (int_t g: adj[i]) cout<<g<<' ';
			cout<<endl;
		}
	}
	
	mcmf_graph(int_t nn=1)                    // Constructor
	{
		n=nn;
	}
	
	void reset()
	{
		lis.clear();
		lis_t.clear();
		for (int_t i=0;i<n;i++) adj[i].clear();
	}
	void add_edge(int_t u, int_t v, int_t cap, int_t cost) // Adds an edge to the graph, as well as its residual edge.
	{
		int_t id=lis.size()-1;
		lis.push_back(edge(u,v,id+2,cap,cost));     // Adds edge to lis
		adj[u].push_back(id+1);                // Adds newly created edge's id to u's adjacency list
		lis.push_back(edge(v,u,id+1,0,-cost));         // Same with residual edge
		adj[v].push_back(id+2);
	}
	
	void setn(int_t nn)
	{
		n=nn;
	}
	int_t calc_flow(int_t ss, int_t tt, int_t kk)        // Calculate the maximum flow
	{
		// Some initialization stuff.
		s=ss; t=tt;
		res=0;
		resc=0;
		int_t cycle=0;
		lis_t=lis;
		while (res<kk)                           // Loops the algorithm until there's no more blocking flows.
		{
			// cout<<"cycle "<<cycle<<' '<<res<<endl;
		    cycle++;
		    vector<int_t> ind=spfa();
		    int_t addable=kk-res;
		    for (int_t g : ind)
		    {
		        addable=min(addable,lis_t[g].cap);
		    }
		    res+=addable;
		    // cout<<addable<<endl;
		    for (int_t g : ind)
		    {
		        resc+=lis_t[g].cost*addable;
		        lis_t[g].cap-=addable;
		        lis_t[lis_t[g].rev].cap+=addable;
		    }
		}
		return resc;
	}
};
mcmf_graph gr;

vector<int> vec;
ll n,m,i,j,k,t,t1,u,v,a,b;
ll arr[2201];
ll brr[2201];
int main()
{
	fio;
	cin>>n>>m;
	gr.setn(n*2+2);
	for (i=1;i<=n;i++) {
		cin>>arr[i];
		gr.add_edge(0,i,1,arr[i]);
		gr.add_edge(i,i+n,1,0);
	}
	for (i=1;i<=n;i++) {
		cin>>brr[i];
		gr.add_edge(i+n,2*n+1,1,brr[i]);
	}
	for (i=1;i<n;i++) {
		gr.add_edge(i+n,i+1+n,m,0);
	}
	cout<<gr.calc_flow(0,2*n+1,m);
}