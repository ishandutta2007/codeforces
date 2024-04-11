/*
	Normie's Template v2.0
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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
int dp[2001][2048];
int maxx[2001], maxx2[2001][2048];
int c[10001];
int pre[10001];
int yeld[2048];
int l[2001],s[2001];
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>l[i];
	for (i=1;i<=n;i++) cin>>s[i];
	for (i=1;i<=n+m;i++)
	{
		cin>>c[i];
		pre[i]=pre[i-1]+c[i];
	}
	for (i=0;i<2048;i++) 
	{
		for (j=0;i&(1<<j);j++);
		yeld[i]=j+1;
	}
	for (i=1;i<=n;i++) for (j=0;j<2048;j++)
	{
		k=(j+1)%2048;
		for (u=0;u<11;u++) if (l[i]+u<=m) dp[i][j]=max(dp[i][j],maxx2[l[i]+u][k>>u]);
		if (l[i]+11<=m) dp[i][j]=max(dp[i][j],maxx[l[i]+11]);
		dp[i][j]+=pre[l[i]+yeld[j]-1]-pre[l[i]-1]-s[i];
		maxx2[l[i]][j]=max(maxx2[l[i]][j],dp[i][j]);
		if (j==0) 
		{
			b=max(b,dp[i][j]);
			for (k=1;k<=l[i];k++) maxx[k]=max(maxx[k],dp[i][j]);
		}
	//	if (j<32) cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
	}
	cout<<b;
	
}