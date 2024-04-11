#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,m,d,dp[2][369][369];

int main()
{
	long long i,j,r,ii,jj,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	if(n>m)
	{
		printf("0\n");
		return 0;
	}
	dp[0][0][0]=1;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			for(r=0;r<=j;r++)
			{
				for(ii=i==d;ii<2;ii++)
				{
					for(jj=0;jj<2;jj++)
					{
						if(j+ii<=n&&r+ii-jj>=0)
						{
							dp[1][j+ii][r+ii-jj]=(dp[1][j+ii][r+ii-jj]+dp[0][j][r])%dv;
						}
					}
				}
			}
		}
		for(j=0;j<=n;j++)
		{
			for(r=0;r<=j;r++)
			{
				dp[0][j][r]=dp[1][j][r];
				dp[1][j][r]=0;
			}
		}
	}
	z=dp[0][n][0];
	for(i=1;i<=n;i++)
	{
		z=z*i%dv;
	}
	printf("%lld\n",z);
}