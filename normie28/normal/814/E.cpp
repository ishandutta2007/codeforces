/*
	Normie's Template v2.2
	Changes:
	Added MODulo binpow and inverse.
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
const int N=50+5;
ll g[N][N][N],f[N][N];
ll fac[N<<1],inv[N<<1];
ll ksm(ll b,int n){
	ll res=1;
	while(n){ 
		if(n&1) res=res*b%MOD;
		b=b*b%MOD;n>>=1;
	}
	return res;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=1ll*i*fac[i-1]%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	for(int i=n-1;i>=0;--i)
		inv[i]=1ll*(i+1)*inv[i+1]%MOD;
}
ll C(int n,int m){
	if(n<m) return 0;
	return fac[n]*inv[m]%MOD*inv[n-m]%MOD;
}
void add(ll &x,ll y){
	x=(x+y)%MOD;
}
int d[N],C2[N],C3[N];
int main(){
    fio;
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>d[i];
	init(n+n);
	g[0][0][0]=1;
	for(int i=0;i<=n;++i)
		for(int j=0;i+j<=n;++j)
			for(int k=0;i+j+k<=n;++k){
				if(!i){
					if(!j){
						for(int l=3;l<=k;++l)
							add(g[i][j][k],g[i][j][k-l]*C(k-1,l-1)%MOD*fac[l]%MOD*ksm(l+l,MOD-2)%MOD);
					}
					else{
						if(j>=2) add(g[i][j][k],1ll*(j-1)*g[i][j-2][k]%MOD);
						if(k>=1) add(g[i][j][k],1ll*k*g[i][j][k-1]%MOD); 
					}
				}
				else{
					if(j>=1) add(g[i][j][k],1ll*j*g[i-1][j-1][k]%MOD);
					if(k>=1) add(g[i][j][k],1ll*k*g[i-1][j+1][k-1]%MOD);
				}
			}
	for(int i=1;i<=n;++i)
		C2[i]=C2[i-1]+(d[i]==2),
		C3[i]=C3[i-1]+(d[i]==3);
	f[d[1]+1][d[1]]=1;
	for(int i=d[1]+2;i<=n;++i)
		for(int j=1;j<=i-(d[1]+1);++j){
			int c2=0,c3=0;
			for(int k=1;k<i-j;++k)
				d[i-j-k+1]==2?++c2:++c3,
				add(f[i][j],f[i-j][k]*g[j][c2][c3]%MOD);
		}
	ll ans=0;int c2=0,c3=0;
	for(int i=1;i<n;++i)
		d[n-i+1]==2?++c2:++c3,
		add(ans,f[n][i]*g[0][c2][c3]%MOD);
	cout<<ans;
}