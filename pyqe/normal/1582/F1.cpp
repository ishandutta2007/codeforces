#include <bits/stdc++.h>

using namespace std;

const long long d=10,inf=1e18;
long long n,dp[2][1ll<<d],sq[100069],zs=0;

int main()
{
	long long i,j,ii,k;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<1ll<<d;i++)
		{
			dp[ii][i]=inf;
		}
		dp[ii][0]=-1;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=0;j<1ll<<d;j++)
		{
			if(dp[0][j]<k)
			{
				dp[1][j^k]=min(dp[1][j^k],k);
			}
		}
		for(j=0;j<1ll<<d;j++)
		{
			dp[0][j]=dp[1][j];
		}
	}
	for(i=0;i<1ll<<d;i++)
	{
		if(dp[0][i]!=inf)
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}