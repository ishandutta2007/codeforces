#include <bits/stdc++.h>

using namespace std;

long long n=19,d=3,dp[20][4][2];

long long val(long long x)
{
	long long i,j,ii,k,z=0;
	
	for(i=1;i<=n;i++)
	{
		k=x%10;
		x/=10;
		for(j=0;j<=d;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[i][j][ii]=dp[i-1][j][ii||k];
			}
			if(j)
			{
				dp[i][j][0]+=dp[i-1][j-1][0]*!!k+dp[i-1][j-1][1]*max(k-1,0ll);
				dp[i][j][1]+=dp[i-1][j-1][1]*9;
			}
		}
	}
	for(i=0;i<=3;i++)
	{
		z+=dp[n][i][0];
	}
	return z;
}

int main()
{
	long long t,rr,ii,k,l;
	
	for(ii=0;ii<2;ii++)
	{
		dp[0][0][ii]=1;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",val(l)-val(k-1));
	}
}