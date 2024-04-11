#include <bits/stdc++.h>

using namespace std;

long long n,a[1000069],dp[2][1ll<<21][2];

int main()
{
	long long i,j,ii,mk,mkk,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		dp[0][a[i]][1]=dp[0][a[i]][0];
		dp[0][a[i]][0]=i;
	}
	for(i=0;i<21;i++)
	{
		for(mk=0;mk<1ll<<21;mk++)
		{
			if(mk>>i&1)
			{
				for(ii=0;ii<2;ii++)
				{
					dp[1][mk][ii]=dp[0][mk][ii];
				}
			}
			else
			{
				mkk=mk|1ll<<i;
				dp[1][mk][0]=max(dp[0][mk][0],dp[0][mkk][0]);
				dp[1][mk][1]=max(min(dp[0][mk][0],dp[0][mkk][0]),max(dp[0][mk][1],dp[0][mkk][1]));
			}
		}
		for(mk=0;mk<1ll<<21;mk++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[0][mk][ii]=dp[1][mk][ii];
			}
		}
	}
	for(i=1;i<=n-2;i++)
	{
		mk=0;
		for(j=20;j+1;j--)
		{
			if(!(a[i]>>j&1))
			{
				mkk=mk|1ll<<j;
				if(dp[0][mkk][1]>i)
				{
					mk=mkk;
				}
			}
		}
		z=max(z,a[i]|mk);
	}
	printf("%lld\n",z);
}