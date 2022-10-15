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
#define maxn 1000100
#define mod 1000000007
#define inv 500000004
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
//---------END-------//
int n,mmax,s[maxn],num[maxn],cnt[maxn],f[maxn],g[20][maxn],g0[20][maxn],ans1[maxn],ans2[maxn],ans3[maxn],ans[maxn];
int mo(int x,int y){return x+y<mod?x+y:x+y-mod;}
int dev(int x,int y){return x-y>=0?x-y:x-y+mod;}
int mul(int x,int y){return 1ll*x*y%mod;}
void fwt_xor(int *now,int len,int pd)
{
	for(int i=1;i<len;i<<=1)
		for(int j=0;j<len;j+=(i<<1))
			for(int k=0;k<i;k++){
				int x=now[j+k],y=now[i+j+k];
				now[j+k]=mo(x,y); now[i+j+k]=dev(x,y);
				if(pd==-1) now[j+k]=mul(now[j+k],inv),now[i+j+k]=mul(now[i+j+k],inv);
			}
}
void work1()
{
	for(int j=0;j<=17;j++)
		for(int i=0;i<mmax;i++)
			if(i&(1<<j)) for(int k=0;k<=17;k++)
				g0[k][i]=mo(g0[k][i],g0[k][i-(1<<j)]);
	for(int x=1;x<=17;x++)
		for(int i=0;i<=x;i++)
			for(int j=0;j<mmax;j++)
				g[x][j]=mo(g[x][j],mul(g0[x-i][j],g0[i][j]));
	for(int j=0;j<=17;j++)
		for(int i=0;i<mmax;i++)
			if(i&(1<<j)) for(int k=0;k<=17;k++)
				g[k][i]=dev(g[k][i],g[k][i-(1<<j)]);
	for(int i=0;i<mmax;i++) ans1[i]=mo(ans1[i],mul(f[i],g[num[i]][i]));
}
void work2()
{
	fwt_xor(cnt,mmax,1); 
	for(int i=0;i<mmax;i++) cnt[i]=mul(cnt[i],cnt[i]);
	fwt_xor(cnt,mmax,-1);
	for(int i=0;i<mmax;i++) ans2[i]=mul(f[i],cnt[i]);
} 
void work3()
{
	for(int i=1;i<mmax;i<<=1)
		for(int j=0;j<mmax;j++)
			if(!(i&j)) ans1[j]=mo(ans1[j],ans1[i|j]),ans2[j]=mo(ans2[j],ans2[i|j]),ans3[j]=mo(ans3[j],ans3[i|j]);
	for(int i=1;i<mmax;i++)
		ans[i]=mul(ans1[i],mul(ans2[i],ans3[i]));
	for(int i=1;i<mmax;i<<=1)
		for(int j=0;j<mmax;j++)
			if(!(i&j)) ans[j]=dev(ans[j],ans[i|j]);
	for(int i=1;i<=17;i++)
		ans[1]=mo(ans[1],ans[1<<i]);
}
int main()
{
    fio;
	cin>>n; mmax=(1<<17);
	for(int i=1;i<=n;i++) cin>>s[i],cnt[s[i]]++;
	f[1]=1;
	for(int i=2;i<=mmax;i++) f[i]=mo(f[i-1],f[i-2]);
	for(int i=0;i<mmax;i++) ans3[i]=mul(f[i],cnt[i]);
	for(int i=1;i<=mmax;i++)
		for(int j=0;j<=17;j++)
			if(i&(1<<j)) num[i]++;
	for(int i=1;i<=n;i++) g0[num[s[i]]][s[i]]++;
	work1(); work2(); work3();
	cout<<ans[1];
}