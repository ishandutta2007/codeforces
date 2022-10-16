#include <bits/stdc++.h>

using namespace std;

long long n,dp[2][3],inf=1e18;

int main()
{
	long long i,j,r,k,z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<3;i++)
	{
		dp[0][i]=inf;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=0;j<3;j++)
		{
			dp[1][j]=inf;
			if((j&k)==j)
			{
				for(r=0;r<3;r++)
				{
					if((r&j)==0)
					{
						dp[1][j]=min(dp[1][j],dp[0][r]+!j);
					}
				}
			}
		}
		for(j=0;j<3;j++)
		{
			dp[0][j]=dp[1][j];
		}
	}
	for(i=0;i<3;i++)
	{
		z=min(z,dp[0][i]);
	}
	printf("%lld\n",z);
}