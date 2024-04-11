#include <bits/stdc++.h>

using namespace std;

long long n,d,a[2][200069],dp[2][200069];

int main()
{
	long long i,ii;
	
	scanf("%lld%lld",&n,&d);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<n;i++)
		{
			scanf("%lld",&a[ii][i]);
		}
	}
	dp[0][0]=0;
	dp[1][0]=1e18;
	printf("0");
	for(i=1;i<n;i++)
	{
		dp[0][i]=min(dp[0][i-1],dp[1][i-1])+a[0][i];
		dp[1][i]=min(dp[0][i-1]+d,dp[1][i-1])+a[1][i];
		printf(" %lld",min(dp[0][i],dp[1][i]));
	}
	printf("\n");
}