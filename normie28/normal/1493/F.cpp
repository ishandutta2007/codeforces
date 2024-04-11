// Problem: F. Enchanted Matrix
// Contest: Codeforces - Codeforces Round #705 (Div. 2)
// URL: https://codeforces.com/contest/1493/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
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
vector<int> vec;
int n,m,i,j,k,t,t1,u,v,a,b;
int res=1;
int iter=0;
int ask(int r, int c, int x1, int y1, int x2, int y2)
{
	iter++;
//	cout<<"debug "<<r<<' '<<c<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	assert (iter<=3*int(floor(log2(m+n)))); 
	assert ((1<=r)and(r<=n));
	assert ((1<=x1)and(x1<=n));
	assert ((1<=x2)and(x2<=n));
	assert ((1<=c)and(c<=m));
	assert ((1<=y1)and(y1<=m));
	assert ((1<=y2)and(y2<=m));
	cout<<"? "<<r<<' '<<c<<' '<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
	int x;
	cin>>x;
	return x;
}
int checkr(int r, int l)
{
//	cout<<"checkr "<<l<<' '<<r<<endl;
	if (l==r) return 1;
	int u=l;
	while(true)
	{
//		cout<<u<<' '<<r<<endl;
		if (u*2<r)
		{
			if (!ask(u,m,1,1,u+1,1)) return 0;
			u*=2;
		}
		else
		{
			if (!ask(r-u,m,u-(r-u)+1,1,u+1,1)) return 0;
			return 1;
		}
	}
}
int checkc(int r, int l)
{
//	cout<<"checkc "<<l<<' '<<r<<endl;
	if (l==r) return 1;
	int u=l;
	while(true)
	{
//		cout<<u<<' '<<r<<endl;
		if (u*2<r)
		{
			if (!ask(n,u,1,1,1,u+1)) return 0;
			u*=2;
		}
		else
		{
			if (!ask(n,r-u,1,u-(r-u)+1,1,u+1)) return 0;
			return 1;
		}
	}
}
int dp[10001];
int main()
{
	fio;
	cin>>n>>m;
	for (i=n;i>=1;i--) dp[i]=1;
	for (i=n-1;i>=1;i--)
	{
		if (n%i)
		{
			dp[i]=0;
			continue;
		}
		b=n;
		for (j=i*2;j<=n;j+=i) if (n%j==0)
		{
			b=__gcd(b,j);
			if (!dp[j]) dp[i]=0;
		}
		if (!dp[i]) continue;
		dp[i]=checkr(b,i);
	}
	a=0;
	for (i=1;i<=n;i++) a+=dp[i];
	res*=a;
	
	
	
	for (i=m;i>=1;i--) dp[i]=1;
	for (i=m-1;i>=1;i--)
	{
		if (m%i)
		{
			dp[i]=0;
			continue;
		}
		b=m;
		for (j=i*2;j<=m;j+=i) if (m%j==0)
		{
			b=__gcd(b,j);
			if (!dp[j]) dp[i]=0;
		}
		if (!dp[i]) continue;
		dp[i]=checkc(b,i);
	}
	a=0;
	for (i=1;i<=m;i++) a+=dp[i];
	res*=a;
	cout<<"! "<<res<<endl;
}