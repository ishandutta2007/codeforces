// Problem: D. Two Melodies
// Contest: Codeforces - Educational Codeforces Round 22
// URL: https://codeforces.com/problemset/problem/813/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int arr[5001];
int ord[100011];
int res=0;
int rowdiff[5001][5001];
int coldiff[5001][5001];
int rowmod[5001][7];
int colmod[5001][7];
int dp[5001];
int dp2[5001];
int main()
{
	fio;
	cin>>n;
	for (i=1;i<=n;i++)
	{
		cin>>arr[i];
		vec.push_back(arr[i]);
	}
	for (i=1;i<=n;i++) 
	{
		for (j=1;j<i;j++) if (((arr[i]%7)==(arr[j]%7))or(abs(arr[i]-arr[j])==1)) dp2[i]=max(dp2[i],dp2[j]);
		dp2[i]++;
	//	cout<<i<<' '<<dp2[i]<<endl;
	}
	sort(vec.begin(),vec.end());
	auto it=unique(vec.begin(),vec.end());
	vec.erase(it,vec.end());
	for (i=0;i<vec.size();i++) ord[vec[i]]=i+1;
	for (k=n;k>=1;k--)
	{
	j=k;
	for (i=k-1;i>=1;i--)
	{
		u=0;
		u=max(u,rowdiff[i][ord[arr[j]-1]]);
		u=max(u,rowdiff[i][ord[arr[j]+1]]);
		u=max(u,coldiff[j][ord[arr[i]-1]]);
		u=max(u,coldiff[j][ord[arr[i]+1]]);
		u=max(u,rowmod[i][arr[j]%7]);
		u=max(u,colmod[j][arr[i]%7]);
		u++;
		res=max(res,u+dp2[i]);
		dp[i]=u;
	//	cout<<i<<' '<<j<<' '<<u<<endl;
	}
	for (i=k-1;i>=1;i--)
	{
		chkmax(rowdiff[i][ord[arr[j]]],dp[i]);
		chkmax(coldiff[j][ord[arr[i]]],dp[i]);
		chkmax(rowmod[i][arr[j]%7],dp[i]);
		chkmax(colmod[j][arr[i]%7],dp[i]);
	}
	i=k;
	for (j=k-1;j>=1;j--)
	{
		u=0;
		u=max(u,rowdiff[i][ord[arr[j]-1]]);
		u=max(u,rowdiff[i][ord[arr[j]+1]]);
		u=max(u,coldiff[j][ord[arr[i]-1]]);
		u=max(u,coldiff[j][ord[arr[i]+1]]);
		u=max(u,rowmod[i][arr[j]%7]);
		u=max(u,colmod[j][arr[i]%7]);
		u++;
		res=max(res,u+dp2[j]);
		dp[j]=u;
	//	cout<<i<<' '<<j<<' '<<u<<endl;
	}
	for (j=k-1;j>=1;j--)
	{
		chkmax(rowdiff[i][ord[arr[j]]],dp[j]);
		chkmax(coldiff[j][ord[arr[i]]],dp[j]);
		chkmax(rowmod[i][arr[j]%7],dp[j]);
		chkmax(colmod[j][arr[i]%7],dp[j]);
	}
	}
	cout<<res;
}