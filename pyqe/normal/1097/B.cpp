#include <bits/stdc++.h>

using namespace std;

long long n,d=360;
bitset<360> dp[2];

int main()
{
	long long i,j,k;
	
	scanf("%lld",&n);
	dp[0][0]=1;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=0;j<d;j++)
		{
			if(dp[0][j])
			{
				dp[1][(j+k)%d]=1;
				dp[1][(j+d-k)%d]=1;
			}
		}
		for(j=0;j<d;j++)
		{
			dp[0][j]=dp[1][j];
			dp[1][j]=0;
		}
	}
	if(dp[0][0])
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}