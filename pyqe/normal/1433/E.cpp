#include <bits/stdc++.h>

using namespace std;

long long n,dp[2][10];

int main()
{
	long long i,j,z;
	
	scanf("%lld",&n);
	dp[0][0]=1;
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n/2-1;j++)
		{
			dp[1][j]=dp[0][j];
			if(j)
			{
				dp[1][j]+=dp[0][j-1];
			}
		}
		for(j=0;j<=n/2-1;j++)
		{
			dp[0][j]=dp[1][j];
		}
	}
	z=dp[0][n/2-1];
	for(i=1;i<=n/2-1;i++)
	{
		z*=i*i;
	}
	printf("%lld\n",z);
}