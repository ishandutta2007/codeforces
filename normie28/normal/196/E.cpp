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
vector<piii(ll)> vec;
vector<pii(ll)> gt[100001];
ll n,m,i,j,k,t,t1,u,v,a,b;
vector<ll> portal;
ll isportal[100001];
pii(ll) dis[100001];
struct cmp
{
	int operator()(piii(ll) a, piii(ll) b)
	{
		return (a.p1>b.p1);
	}
};
ll res=0;
priority_queue<piii(ll),vector<piii(ll)>,cmp> pq;


struct dsu
{
	ll n,par[1000100],h[1000100],sz[1000100];
	dsu (ll n)
	{
		for (ll i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
			h[i]=1;
		}
		this->n=n;
	}
	
	void reset (ll n)
	{
		for (ll i=1;i<=n;i++)
		{
			par[i]=i;
			sz[i]=1;
			h[i]=1;
		}
		this->n=n;
	}
	ll get_par(ll x)
	{
		if (par[par[x]]==par[x]) return par[x];
		else return par[x]=get_par(par[x]);
	}
	ll check_same(ll a, ll b)
	{
		return (get_par(a)==get_par(b));
	}
	ll add_edge(ll a, ll b)
	{
		ll ha=get_par(a),hb=get_par(b);
		if (ha!=hb)
		{
			if (h[ha]<h[hb])
			{
				par[ha]=hb;
				sz[hb]+=sz[ha];
			}
			else
			if (h[ha]>h[hb])
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
			}
			else
			{
				par[hb]=ha;
				sz[ha]+=sz[hb];
				h[ha]++;
			}
			return 1;
		}
		else return 0;
	}
};


	dsu gr(100001);
int main()
{
	fio;
	cin>>n>>m;
	if (n==1) return cout<<0,0;
	for (i=1;i<=m;i++)
	{
		cin>>u>>v>>a;
		gt[u].push_back({v,a});
		gt[v].push_back({u,a});
	}
	cin>>t;
	for (i=1;i<=t;i++)
	{
		cin>>u;
		portal.push_back(u);
		isportal[u]=1;
	}
	for (i=1;i<=n;i++) dis[i]={1e18,-1};
	for (auto g: portal) 
	{
		dis[g]={0,g};
		pq.push({0,{g,g}});
	}
	while(pq.size())
	{
		auto pp=pq.top();
//		cout<<pp.p1<<' '<<pp.p2<<' '<<pp.p3<<endl;
		pq.pop();
		if (pp.p1!=dis[pp.p2].fi) continue;
		for (auto g : gt[pp.p2]) if (pp.p1+g.se<dis[g.fi].fi)
		{
			dis[g.fi]={pp.p1+g.se,pp.p3};
			pq.push({pp.p1+g.se,{g.fi,pp.p3}});
		}
	}
	
	res+=dis[1].fi;
	for (i=1;i<=n;i++) for (auto g : gt[i]) if (dis[i].se!=dis[g.fi].se)
	{
		vec.push_back({dis[i].fi+dis[g.fi].fi+g.se,{dis[i].se,dis[g.fi].se}});
	}
	sort(vec.begin(),vec.end(),[](piii(ll) a, piii(ll) b){
		return (a.p1<b.p1);
	});
	for (auto g : vec) if (gr.add_edge(g.p2,g.p3)) res+=g.p1;
	cout<<res;
	
}