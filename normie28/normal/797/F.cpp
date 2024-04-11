// Problem: F. Mice and Holes
// Contest: Codeforces - Educational Codeforces Round 19
// URL: https://codeforces.com/problemset/problem/797/F
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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

//---------END-------//
const int N=5003;
const ll inf=1LL<<60;
struct node { int x,s; } v[N];
ll f[N][N],z[N],Z,d;
int q[N],x[N],i,j,k,n,m,l,r,s,a,b;
char c;

bool cmp(node a,node b){ return a.x<b.x; }
 
int main()
{
    fio;
    cin>>n>>m;
	for (i=1;i<=n;i++) cin>>x[i];
	for (i=1;i<=m;i++) 
	{
		cin>>a>>b;
		v[i]=(node){a,b};
		s+=v[i].s;
	}
	if (s<n) return cout<<-1,0;
	sort(x+1,x+n+1),sort(v+1,v+m+1,cmp);
	for (i=1;i<=n;i++) f[i][0]=inf;
	for (j=1;j<=m;j++)
	{
		l=1,r=1,Z=0;
		q[1]=0,z[1]=abs(x[1]-v[j].x);
		for (i=1;i<=n;i++)
		{
			for (;l<=r&&i-q[l]>v[j].s;l++);
			f[i][j]=f[i][j-1];
			if (l<=r) f[i][j]=min(f[i][j],z[l]+Z);
			d=f[i][j-1]-Z;
			for (;l<=r&&d<=z[r];r--);
			q[++r]=i,z[r]=d,Z+=abs(x[i+1]-v[j].x);
		}
	}
    cout<<f[n][m];
}