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
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int A,B;
ld pA[2001];
ld pB[2001];
ld pAB[2001];
pair<ld,int> ev[2001][2001];
pair<ld,int> x,y,z;
int main()
{
	fio;
	cin>>n>>A>>B;
	for (i=0;i<n;i++) cin>>pA[i];
	for (i=0;i<n;i++) cin>>pB[i];
	a=0;
for (i=0;i<n;i++) {pAB[i]=pA[i]+pB[i]-pA[i]*pB[i];  
	if (pA[i]) a=1;
	if (pB[i]) a=1;
// cout<<i<<' '<<pAB[i]<<endl;
}
	if (!a) return cout<<0,0;
	ld l=0,r=1,mid;
	for (t=0;t<15;t++) {
		mid=(l+r)/2;
		for (i=0;i<=n;i++) for (j=0;j<=A;j++) {
			ev[i][j]={-1e9,0};
		}
		ev[0][0]={0,0};
		for (i=0;i<n;i++) {
			for (j=1;j<=A;j++) {
				x=ev[i+1][j];
				y=ev[i][j];
				x=max(x,y);
				y.se--;
				y.fi+=pB[i]-mid;
				x=max(x,y);

				y={ev[i][j-1].fi+pA[i],ev[i][j-1].se};
				x=max(x,y);
				y={ev[i][j-1].fi+pAB[i]-mid,ev[i][j-1].se-1};
				x=max(x,y);
				ev[i+1][j]=x;
				
			}
			
				x=ev[i+1][0];
				y=ev[i][0];
				x=max(x,y);
				y.se--;
				y.fi+=pB[i]-mid;
				x=max(x,y);
				ev[i+1][0]=x;
		}
		if (-ev[n][A].se<=B) r=mid; else l=mid;
	}
	// cout<<l<<' '<<r<<endl;
	mid=r;

		for (i=0;i<=n;i++) for (j=0;j<=A;j++) {
			ev[i][j]={-1e9,0};
		}
		ev[0][0]={0,0};
		for (i=0;i<n;i++) {
			for (j=1;j<=A;j++) {
				x=ev[i+1][j];
				y=ev[i][j];
				x=max(x,y);
				y.se--;
				y.fi+=pB[i]-mid;
				x=max(x,y);

				y={ev[i][j-1].fi+pA[i],ev[i][j-1].se};
				x=max(x,y);
				y={ev[i][j-1].fi+pAB[i]-mid,ev[i][j-1].se-1};
				x=max(x,y);
				ev[i+1][j]=x;
				
			// cout<<i<<' '<<j<<' '<<ev[i][j].fi<<' '<<ev[i][j].se<<endl;
			}
			
				x=ev[i+1][0];
				y=ev[i][0];
				x=max(x,y);
				y.se--;
				y.fi+=pB[i]-mid;
				x=max(x,y);
				ev[i+1][0]=x;
				
			// cout<<i<<' '<<0<<' '<<ev[i][0].fi<<' '<<ev[i][0].se<<endl;
		}
	// cout<<mid<<' '<<ev[n][A].fi<<' '<<ev[n][A].se<<endl;
	cout<<fixed<<setprecision(9)<<ev[n][A].fi+mid*(B);
}
// a;