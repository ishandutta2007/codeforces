#include <bits/stdc++.h>

using namespace std;

const long long ma=125e3;
long long n,d,fc[569],cb[569][569],dp[2][2][250069],dv;

int main()
{
	long long i,j,r,ii,z=0;
	
	scanf("%lld%lld",&n,&dv);
	d=n*(n-1)/2;
	fc[0]=1;
	cb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		fc[i]=fc[i-1]*i%dv;
		for(j=0;j<=i;j++)
		{
			cb[i][j]=cb[i-1][j];
			if(j)
			{
				cb[i][j]=(cb[i][j]+cb[i-1][j-1])%dv;
			}
		}
	}
	dp[0][0][ma]=1;
	for(i=1;i<=n;i++)
	{
		for(j=-i+1;j<=i-1;j++)
		{
			for(r=max(-d+j,-d);r<=min(d+j,d);r++)
			{
				for(ii=0;ii<2;ii++)
				{
					dp[1][ii][ma+r]=(dp[1][ii][ma+r]+dp[0][ii][ma+r-j]*(i-1-abs(j)))%dv;
					dp[1][0][ma+r]=(dp[1][0][ma+r]+dp[0][ii][ma+r-j]*(j>=0))%dv;
					dp[1][1][ma+r]=(dp[1][1][ma+r]+dp[0][ii][ma+r-j]*(j<0))%dv;
				}
			}
		}
		for(ii=0;ii<2;ii++)
		{
			for(j=-d;j<=d;j++)
			{
				dp[0][ii][ma+j]=dp[1][ii][ma+j];
				dp[1][ii][ma+j]=0;
				if(ii&&j>0)
				{
					z=(z+dp[0][ii][ma+j]*cb[n][i]%dv*fc[n-i])%dv;
				}
			}
		}
	}
	printf("%lld\n",z);
}