#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],dp[2][2],inf=1e18;

int main()
{
	long long i,ii,z=-inf;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			dp[1][ii]=max(dp[0][ii],dp[0][!ii]+a[ii][i]);
		}
		for(ii=0;ii<2;ii++)
		{
			dp[0][ii]=dp[1][ii];
			if(i==n)
			{
				z=max(z,dp[0][ii]);
			}
		}
	}
	printf("%lld\n",z);
}