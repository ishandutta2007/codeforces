//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 10010
using namespace std;
ll n,a[N],dp[2][2020],ans;
void solve()
{
	ll i,j,k;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	memset(dp[0],63,sizeof(dp[0]));
	dp[0][0]=0;
	for(i=0;i<n;i++)
	{
		memset(dp[(i&1)^1],63,sizeof(dp[(i&1)^1]));
		for(j=0;j<=2000;j++)
		{
			if(j>=a[i])
			{
				dp[(i&1)^1][j]=min(dp[(i&1)^1][j],max(dp[i&1][j-a[i]],j));
			}
			if(j+a[i]<=2000)
			{
				dp[(i&1)^1][j]=min(dp[(i&1)^1][j],dp[i&1][j+a[i]]);
			}
		}
		for(j=0;j<a[i];j++)
		{
			dp[(i&1)^1][0]=min(dp[(i&1)^1][0],dp[i&1][j]+a[i]-j);
		}
	}
	ans=LINF;
	for(j=0;j<=1000;j++)
	{
		ans=min(ans,dp[n&1][j]);
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	ll T;
	scanf("%lld",&T);
	while(T--)
	{
		solve();
	}
	return 0;
}