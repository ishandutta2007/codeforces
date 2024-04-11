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
#define MOD (ll(1000000007))
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
#define N 105
ll fir[N],to[2*N],nxt[2*N],cnt;
void adde(ll a,ll b)
{
	to[++cnt]=b;nxt[cnt]=fir[a];fir[a]=cnt;
	to[++cnt]=a;nxt[cnt]=fir[b];fir[b]=cnt;
}
ll fac[N],finv[N];
void shai()
{
	fac[0]=fac[1]=1;
	for(ll i=2;i<=100;i++)fac[i]=1ll*fac[i-1]*i%MOD;
	finv[100]=INV(fac[100],MOD);
	for(ll i=100;i>=1;i--)finv[i-1]=1ll*finv[i]*i%MOD;
}
ll C(ll x,ll y)
{
	return 1ll*fac[x]*finv[y]%MOD*finv[x-y]%MOD;
}
ll siz[N],g[N],f[N][N][2],tmp[N][2];
void dfs(ll u,ll ff)
{
	siz[u]=1;f[u][0][1]=f[u][0][0]=1;
	for(ll v,p=fir[u];p;p=nxt[p]){
		if((v=to[p])!=ff){
			dfs(v,u);
			for(ll i=0;i<siz[u]+siz[v];i++)
				tmp[i][0]=tmp[i][1]=0;
			for(ll i=0;i<siz[u];i++){
				for(ll j=0;j<siz[v];j++){
					tmp[i+j][0]=(1ll*tmp[i+j][0]+1ll*f[u][i][0]*f[v][j][0])%MOD;
					tmp[i+j][1]=(1ll*tmp[i+j][1]+1ll*f[u][i][0]*f[v][j][1]+1ll*f[u][i][1]*f[v][j][0])%MOD;
					tmp[i+j+1][0]=(1ll*tmp[i+j+1][0]+1ll*f[u][i][0]*f[v][j][1])%MOD;
					tmp[i+j+1][1]=(1ll*tmp[i+j+1][1]+1ll*f[u][i][1]*f[v][j][1])%MOD;
				}
			}
			siz[u]+=siz[v];
			for(ll i=0;i<siz[u];i++)
				f[u][i][0]=tmp[i][0],f[u][i][1]=tmp[i][1];
		}
	}
}
int main()
{
	shai();
	ll n,i,j,u,v;
	cin>>n;
	for(i=1;i<n;i++){cin>>u>>v;adde(u,v);}
	dfs(1,0);g[0]=1;
	for(i=1;i<n;i++)g[i]=1ll*BOW(n,i-1,MOD)*f[1][i][1]%MOD;
	for(i=0;i<n;i++)for(j=0;j<i;j++)g[i]=(g[i]+MOD-1ll*C(n-1-j,n-1-i)*g[j]%MOD)%MOD;
	cout<<g[n-1];
	for(i=n-2;i>=0;i--) cout<<' '<<g[i];
}