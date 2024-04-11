#include <bits/stdc++.h>

using namespace std;

long long n,a[369][369],dp[2][369][369];

int main()
{
	long long i,j,r,ii,iii,k,tg;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[0][i][j]=-1e18;
		}
	}
	dp[0][0][0]=0;
	for(i=1;i<=n*2-1;i++)
	{
		for(j=0;j<=n;j++)
		{
			for(r=0;r<=n;r++)
			{
				dp[1][j][r]=-1e18;
			}
		}
		for(j=1;j<=n;j++)
		{
			for(r=1;r<=n;r++)
			{
				k=0;
				tg=i-j+1;
				if(tg>0&&tg<=n)
				{
					k+=a[tg][j];
				}
				tg=i-r+1;
				if(tg>0&&tg<=n)
				{
					k+=a[tg][r]*(r!=j);
				}
				for(ii=0;ii<2;ii++)
				{
					for(iii=0;iii<2;iii++)
					{
						dp[1][j][r]=max(dp[1][j][r],dp[0][j-ii][r-iii]+k);
					}
				}
			}
		}
		for(j=0;j<=n;j++)
		{
			for(r=0;r<=n;r++)
			{
				dp[0][j][r]=dp[1][j][r];
			}
		}
	}
	printf("%lld\n",dp[0][n][n]);
}