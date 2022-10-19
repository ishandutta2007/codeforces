//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 110
using namespace std;
bool cmp(pair<ll,ll> x,pair<ll,ll> y)
{
	if(x.S>=0&&y.S>=0)
	{
		return (x.F<y.F);
	}
	if(x.S>=0)
	{
		return true;
	}
	if(y.S>=0)
	{
		return false;
	}
	return max(x.F,y.F-x.S)<max(y.F,x.F-y.S);
}
ll n,r,dp[N][60010],ans=-LINF;
pair<ll,ll> a[N];
int main(){
	ll i,j;
	cin>>n>>r;
	for(i=0;i<n;i++)
	{
		cin>>a[i].F>>a[i].S;
	}
	sort(a,a+n,cmp);
	memset(dp,-63,sizeof(dp));
	dp[0][r]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<60010;j++)
		{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			if(j+a[i].S>=0&&j+a[i].S<60010&&j>=a[i].F)
			{
				dp[i+1][j+a[i].S]=max(dp[i+1][j+a[i].S],dp[i][j]+1);
			}
		}
	}
	for(i=0;i<60010;i++)
	{
		ans=max(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}