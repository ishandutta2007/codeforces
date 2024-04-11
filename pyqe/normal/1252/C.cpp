#include <bits/stdc++.h>

using namespace std;

long long d,fq[9],dp[9][6769];

int main()
{
	long long i,j,r,mx=0;
	
	scanf("%lld",&d);
	for(i=1;i<=8;i++)
	{
		scanf("%lld",fq+i);
	}
	for(i=0;i<=8;i++)
	{
		for(j=0;j<=6720;j++)
		{
			dp[i][j]=-1e18;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=8;i++)
	{
		for(j=0;j<=min(fq[i],840/i);j++)
		{
			for(r=i*j;r<=min(d,6720ll);r++)
			{
				dp[i][r]=max(dp[i][r],dp[i-1][r-i*j]+(fq[i]-j)/(840/i));
			}
		}
	}
	for(i=0;i<=min(d,6720ll);i++)
	{
		if(dp[8][i]>=0)
		{
			mx=max(mx,i+min(dp[8][i],(d-i)/840)*840);
		}
	}
	printf("%lld\n",mx);
}