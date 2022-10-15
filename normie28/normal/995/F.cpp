// Problem: F. Cowmpany Cowmpensation
// Contest: Codeforces - Codeforces Round #492 (Div. 1) [Thanks, uDebug!]
// URL: https://codeforces.com/contest/995/problem/F
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
const int N=3005;
struct edge{int to,next;}e[N<<1];
int n,D;
int head[N],cnt;
ll f[N][N],s[N][N],c[N][N],g[N],C[N];
 
inline void add(int x,int y){
	e[++cnt]=(edge){head[x],y};head[x]=cnt;
}
 
inline void dfs(int x){
	for(int i=1;i<=n;i++) f[x][i]=1;
	for(int i=head[x];i;i=e[i].to){
		int k=e[i].next;
		dfs(k);
		for(int j=1;j<=n;j++) f[x][j]=f[x][j]*s[k][j]%MOD;
	}
	for(int i=1;i<=n;i++) s[x][i]=(s[x][i-1]+f[x][i])%MOD;
}
 
 
int main(){
	fio;
	cin>>n>>D;
	for(int i=2;i<=n;i++)
	{
		int x; 
		cin>>x; 
		add(x,i);
	}
	dfs(1);
	for(int i=0;i<=n;i++) c[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
	for(int i=1;i<=n;i++){
		g[i]=f[1][i];
		for(int j=1;j<i;j++) g[i]=(g[i]-g[j]*c[i-1][j-1]%MOD+MOD)%MOD;
	}
	C[0]=1;
	for(int i=1;i<=n;i++) C[i]=C[i-1]*INV(i,MOD)%MOD*(D-i+1)%MOD;
	ll ans=0;
	for(int i=1;i<=n;i++) ans=(ans+C[i]*g[i]%MOD)%MOD;
	cout<<(ans+MOD)%MOD;
}