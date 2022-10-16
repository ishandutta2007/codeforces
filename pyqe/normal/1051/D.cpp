#include <bits/stdc++.h>

using namespace std;

long long n,d,dp[1069][2069][4],dv=998244353;

int main()
{
	long long i,j,mk,mkk,jj,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(mk=0;mk<4;mk++)
	{
		dp[1][1+(__builtin_popcount(mk)==1)][mk]=1;
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<=d;j++)
		{
			for(mk=0;mk<4;mk++)
			{
				for(mkk=0;mkk<4;mkk++)
				{
					if(mk==mkk)
					{
						jj=j;
					}
					else
					{
						jj=j-(__builtin_popcount(mk)==1)-(mk==3-mkk);
					}
					if(jj>=0)
					{
						dp[i][j][mk]=(dp[i][j][mk]+dp[i-1][jj][mkk])%dv;
					}
				}
			}
		}
	}
	for(mk=0;mk<4;mk++)
	{
		z=(z+dp[n][d][mk])%dv;
	}
	printf("%lld\n",z);
}