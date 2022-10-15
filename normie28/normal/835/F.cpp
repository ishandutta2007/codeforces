// Problem: F. Roads in the Kingdom
// Contest: Codeforces - Codeforces Round #427 (Div. 2)
// URL: https://codeforces.com/contest/835/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
 
ll n,cnt=0,tot=0,cir[MAX],vis[MAX],head[MAX];
ll ans1=0,ans2=1e18+5,res,we[MAX],f[MAX],l[MAX],l0[MAX],r[MAX],r0[MAX];
 
struct edge{ll to,wei,nxt;} e[MAX<<1];
inline void adde(ll x,ll y,ll w) {e[++tot]=(edge){y,w,head[x]},head[x]=tot;}
inline ll fnd(ll x,ll fa=-1)
{
	if(vis[x]) return x;else vis[x]=-1;
	for(ll i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) {res=fnd(e[i].to,x);if(res) return cir[++cnt]=x,we[cnt]=e[i].wei,vis[x]=1,res==x?0:res;}
	return 0;
}
inline void dfs(ll x,ll fa=-1)
{
	for(ll i=head[x];i;i=e[i].nxt)
		if(vis[e[i].to]!=1&&e[i].to!=fa)
			dfs(e[i].to,x),ans1=max(ans1,f[x]+f[e[i].to]+e[i].wei),f[x]=max(f[x],f[e[i].to]+e[i].wei);
}
int main()
{
	fio;
	cin>>n,memset(vis,0,sizeof(vis)),memset(f,0,sizeof(f));
	for(ll i=1,x,y,w;i<=n;i++) cin>>x>>y>>w,adde(x,y,w),adde(y,x,w);
	fnd(1),we[0]=0;for(int i=1;i<=cnt;i++) dfs(cir[i]),we[i]+=we[i-1];
    res = l[0] = l0[0] = -1e18;
    for (int i = 1; i <= cnt; i++)
    {
        l0[i] = max(l0[i-1], f[cir[i]] + we[i] + res);
        l[i] = max(l[i-1], f[cir[i]] + we[i]);
        res = max(res, f[cir[i]] - we[i]);
    }
    res = r[cnt+1] = r0[cnt+1] = -1e18;
    for (int i = cnt; i >= 1; i--)
    {
        r0[i] = max(r0[i+1], f[cir[i]] - we[i] + res);
        r[i] = max(r[i+1], f[cir[i]] + we[cnt]- we[i]);
        res = max(res, f[cir[i]] + we[i]);
    }
	for(int i=1;i<=cnt;i++) ans2=min(ans2,max(l[i-1]+r[i],max(l0[i-1],r0[i])));
	return cout<<max(ans1,ans2),0;
}