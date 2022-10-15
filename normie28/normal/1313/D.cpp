
// Problem : D. Happy New Year
// Contest : Codeforces - Codeforces Round #622 (Div. 2)
// URL : https://codeforces.com/contest/1313/problem/D
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
vector<pii(int)> eve;
int l[100001],r[100001],p[100001];
int dp[200001][256];
int all[8];
int n,m,i,j,k,t,t1,u,v,a,b;
int main()
{
	fio;
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
		eve.push_back({l[i],i});
		eve.push_back({r[i]+1,-i});
	}
	sort(eve.begin(),eve.end(),[](pii(int) a, pii(int) b){
		if (a.fi-b.fi) return (a.fi<b.fi);
		else return (a.se<b.se);
	});
	for (i=0;i<(1<<k);i++) dp[0][i]=-2e9;
	dp[0][0]=0;
	for (i=1;i<2*n;i++)
	{
		for (j=0;j<(1<<k);j++) dp[i][j]=-2e9;
		if (eve[i-1].se>0)
		{
			for (u=0;u<k;u++) if (!all[u]) break;
			all[u]=1;
			p[eve[i-1].se]=u;
			for (j=0;j<(1<<k);j++) 
			{
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
			dp[i][j^(1<<u)]=max(dp[i][j^(1<<u)],dp[i-1][j]);
			}
		}
		else
		{
			for (j=0;j<(1<<k);j++) dp[i][j&((1<<k)-1-(1<<(p[-eve[i-1].se])))]=
			max(dp[i][j&((1<<k)-1-(1<<(p[-eve[i-1].se])))],dp[i-1][j]);
			all[p[-eve[i-1].se]]=0;
		}
		for (j=0;j<(1<<k);j++) if (__builtin_popcount(j)%2) dp[i][j]+=eve[i].fi-eve[i-1].fi;
//		cout<<i-1<<' '<<eve[i-1].fi<<' '<<eve[i-1].se<<endl;
//		for (j=0;j<(1<<k);j++) cout<<dp[i][j]<<' ';
		cout<<endl;
	}
	a=0;
	for (i=0;i<(1<<k);i++) a=max(a,dp[2*n-1][i]);
	cout<<a;
}