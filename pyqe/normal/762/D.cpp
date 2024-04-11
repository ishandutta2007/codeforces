#include <bits/stdc++.h>

using namespace std;

long long n,a[100069][3],dp[100069][3][2];

int main()
{
	long long i,j,ii;
	
	scanf("%lld",&n);
	for(j=0;j<3;j++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	dp[1][0][0]=a[1][0];
	dp[1][0][1]=-1e18;
	dp[1][1][0]=dp[1][0][0]+a[1][1];
	dp[1][1][1]=-1e18;
	dp[1][2][0]=dp[1][1][0]+a[1][2];
	dp[1][2][1]=dp[1][1][0]+a[1][2];
	for(i=2;i<=n;i++)
	{
		dp[i][0][0]=max(max(dp[i-1][0][0],dp[i-1][1][0]+a[i][1]),max(dp[i-1][2][0],dp[i-1][0][1])+a[i][1]+a[i][2])+a[i][0];
		dp[i][0][1]=max(dp[i-1][2][0],dp[i-1][0][1])+a[i][0]+a[i][1]+a[i][2];
		dp[i][1][0]=max(dp[i-1][1][0],max(dp[i-1][0][0]+a[i][0],dp[i-1][2][0]+a[i][2]))+a[i][1];
		dp[i][1][1]=-1e18;
		dp[i][2][0]=max(max(dp[i-1][2][0],dp[i-1][1][0]+a[i][1]),max(dp[i-1][0][0],dp[i-1][2][1])+a[i][1]+a[i][0])+a[i][2];
		dp[i][2][1]=max(dp[i-1][0][0],dp[i-1][2][1])+a[i][0]+a[i][1]+a[i][2];
	}
	printf("%lld\n",dp[n][2][0]);
}