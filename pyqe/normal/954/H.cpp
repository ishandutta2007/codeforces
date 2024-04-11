#include <bits/stdc++.h>

using namespace std;

long long n,a[15069],dp[2][10069][2],sq[10069],pwk,dv=1e9+7;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long i,j,ii,ml[2],c=1;
	
	scanf("%lld",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			ml[ii]=1;
		}
		for(j=0;j<=n*2-2;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[1][j][ii]=0;
				if(j)
				{
					dp[1][j][ii]=dp[0][j-1][1];
				}
				dp[1][j][ii]=(dp[1][j][ii]+ml[ii])%dv;
				ml[ii]=ml[ii]*(a[i+j]-(ii&&!j))%dv;
			}
		}
		for(j=0;j<=n*2-2;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[0][j][ii]=dp[1][j][ii];
			}
			sq[j]=(sq[j]+dp[0][j][0]*c)%dv;
		}
		c=c*a[i]%dv;
	}
	c=pw(2,dv-2);
	for(i=1;i<=n*2-2;i++)
	{
		sq[i]=sq[i]*c%dv;
		printf("%lld%c",sq[i]," \n"[i==n*2-2]);
	}
}