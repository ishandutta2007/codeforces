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
#define N 300010
#define M 31
using namespace std;
ll n,dp[N][M],a[N],ans=LINF;
int main(){
	ll i,j;
	scanf("%lld",&n);
	memset(dp[0],63,sizeof(dp));
	for(i=1;i<=n;i++)
	{
		memset(dp[i],63,sizeof(dp[i]));
		scanf("%lld",&a[i]);
	}
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<M;j++)
		{
			dp[i][max((ll)0,j-a[i]/100)]=min(dp[i][max((ll)0,j-a[i]/100)],dp[i-1][j]+a[i]-(j-max((ll)0,j-a[i]/100))*100);
			if(j+a[i]/1000<M)
			{
				dp[i][j+a[i]/1000]=min(dp[i][j+a[i]/1000],dp[i-1][j]+a[i]);
			}
		}
	}
	for(i=0;i<M;i++)
	{
		ans=min(ans,dp[n][i]);
	}
	printf("%lld\n",ans);
	return 0;
}