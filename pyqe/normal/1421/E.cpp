#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,dp[2][3][2][2];

int main()
{
	long long i,j,ii,jj,u,k,pp,*tg,z=-inf;
	
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<3;i++)
		{
			for(jj=0;jj<2;jj++)
			{
				for(pp=0;pp<2;pp++)
				{
					dp[ii][i][jj][pp]=-inf;
				}
			}
		}
	}
	dp[0][0][0][0]=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		for(j=0;j<3;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				for(jj=0;jj<2;jj++)
				{
					for(pp=0;pp<2;pp++)
					{
						u=!pp*2-1;
						tg=&dp[1][(j+!pp)%3][pp][jj||(i&&pp==ii)];
						*tg=max(*tg,dp[0][j][ii][jj]+k*u);
					}
				}
			}
		}
		for(j=0;j<3;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				for(jj=0;jj<2;jj++)
				{
					dp[0][j][ii][jj]=dp[1][j][ii][jj];
					dp[1][j][ii][jj]=-inf;
				}
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		z=max(z,dp[0][2-n%3][ii][n>1]);
	}
	printf("%lld\n",z);
}