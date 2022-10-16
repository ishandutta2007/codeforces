#include <bits/stdc++.h>

using namespace std;

long long n,a[1069],dp[1069][1069][2];

int main()
{
	long long i,j,ii;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				if(i||j)
				{
					dp[i][j][ii]=1e18;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			dp[0][i][ii]=1e18;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				if(!a[i]||ii==a[i]%2)
				{
					if(j>=ii)
					{
						dp[i][j][ii]=min(dp[i-1][j-ii][ii],dp[i-1][j-ii][!ii]+1);
					}
				}
				else
				{
					dp[i][j][ii]=1e18;
				}
			}
		}
	}
	printf("%lld\n",min(dp[n][(n+1)/2][0],dp[n][(n+1)/2][1]));
}