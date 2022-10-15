/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "nim.in"
#define FILE_OUT "nim.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define bi BigInt
#define pi 3.1415926535897
typedef int ll;
// Yes, I read the editorial. I am a noob. Now go ahead and shame on me however much you want
ll n,m,k,c[1001],t1,i,j,minn,maxx,cur,lu,lv;
ll dp[10001][10001],nxt[10001];
ll presum[10001]; vector<ll> buc[20001];
string s,t;
int main ()
{
	cin>>s>>t;
	n=s.length();
	m=t.length();
	for (i=1;i<=n;i++) if (s[i-1]=='.') presum[i]=presum[i-1]-1;
	else presum[i]=presum[i-1]+1;
	for (i=n;i>=0;i--)
	{
		if ((i<n)and(presum[i]<presum[i+1])and(buc[presum[i]+10000].size()))
		{
			nxt[i]=buc[presum[i]+10000][buc[presum[i]+10000].size()-1];
		}
		else nxt[i]=-1;
		buc[presum[i]+10000].push_back(i);
	}
	for (i=n;i>=0;i--) for (j=m;j>=0;j--)
	{
		if ((i==n)and(j==m)) dp[i][j]=0;
		else if (i==n) dp[i][j]=-1e9;
		else
		{
			dp[i][j]=dp[i+1][j];
			if ((j)and(s[i]=='.')) dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
			if ((j<m)and(s[i]==t[j])) dp[i][j]=max(dp[i][j],dp[i+1][j+1]+1);
			if (nxt[i]!=-1) dp[i][j]=max(dp[i][j],dp[nxt[i]][j]+nxt[i]-i);
		}
	}
	cout<<n-dp[0][0];
}