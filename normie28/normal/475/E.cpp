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
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
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
vector<int> gt[2001],gtt[2001];
vector<int> gtb[2001],gtnb[2001];
vector<int> gt2[2001];
int n,m,i,j,k,t,t1,u,v,a,b,res;
int tin[2001],low[2001];

int sz[2001],subt[2001];
int dp[2001];

int banned[2001][2001];

void dfs(int x, int p)
{
	t++;
	tin[x]=t;
	low[x]=t;
	for (int g : gt[x])
	{
		if (g==p);
		else if (tin[g])
		{
			low[x]=min(low[x],tin[g]);
		}
		else
		{
			dfs(g,x);
			low[x]=min(low[x],low[g]);
			gtt[x].push_back(g);
		}
	}
	int cnt=0;
	for (int g : gtt[x])
	{
		if (tin[x]<low[g])
		{
			banned[x][g]=1;
			banned[g][x]=1;
		}
	}
}

void dfs2(int x) {
	tin[x]=i;
	sz[i]++;
	for (auto g : gtnb[x]) if (!tin[g]) dfs2(g);
}

void calc2(int x, int p) {
	subt[x]=sz[x];
	for (auto g : gt2[x]) if (g-p) {calc2(g,x); subt[x]+=subt[g];}
	b+=sz[x]*(subt[x]-sz[x]);
}

int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=m;i++) {
		cin>>u>>v;
		gt[u].push_back(v);
		gt[v].push_back(u);
	}
	dfs(1,1);
	for (i=1;i<=n;i++) {
		for (auto g : gt[i]) {
			if (banned[i][g]) gtb[i].push_back(g);
			else gtnb[i].push_back(g);
		}
	}
	for (i=1;i<=n;i++) {
		tin[i]=0;
	}	
	for (i=1;i<=n;i++) if (!tin[i]) {
		dfs2(i);
		res+=sz[i]*sz[i];
		// cout<<i<<' '<<sz[i]<<endl;
	}
	for (i=1;i<=n;i++) for (auto g : gtb[i]) {
		// cout<<g<<' '<<i<<endl;
		gt2[tin[i]].push_back(tin[g]);
	}
	a=0;
	for (u=1;u<=n;u++) if (tin[u]==u) {
		b=0;
		calc2(u,u);
		for (i=0;i<=n;i++) dp[i]=0; dp[0]=1;
		for (auto g : gt2[u]) for (i=n-sz[u];i>=subt[g];i--) dp[i]|=dp[i-subt[g]];
		v=0;
		for (i=0;i<=n-sz[u];i++) {
			if (dp[i]) v=max(v,i*(n-sz[u]-i));
		}
		// cout<<u<<' '<<res<<' '<<b<<' '<<v<<endl;
		a=max(a,b+v);
	}
	// cout<<n<<' '<<res<<' '<<a<<endl;
	cout<<res+a;
}
// a;