#include <bits/stdc++.h>

using namespace std;

const long long ma=1e4,dv=1e9+7;
long long n,dp[2][20069];

int main()
{
	long long i,j,k,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		dp[0][ma]=(dp[0][ma]+1)%dv;
		for(j=0;j<=ma*2;j++)
		{
			if(j>=k)
			{
				dp[1][j-k]=(dp[1][j-k]+dp[0][j])%dv;
			}
			if(j+k<=ma*2)
			{
				dp[1][j+k]=(dp[1][j+k]+dp[0][j])%dv;
			}
		}
		for(j=0;j<=ma*2;j++)
		{
			dp[0][j]=dp[1][j];
			dp[1][j]=0;
		}
		z=(z+dp[0][ma])%dv;
	}
	printf("%lld\n",z);
}