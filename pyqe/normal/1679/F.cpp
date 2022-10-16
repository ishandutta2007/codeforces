#include <bits/stdc++.h>

using namespace std;

const int mm=10,dv=998244353;
int n,m,am[mm],am2[mm],dp[2][1<<mm];

int main()
{
	int i,j,k,l,mk,mk2,z=0;
	
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&k,&l);
		am[k]|=1<<l;
		am[l]|=1<<k;
		am2[l]|=1<<k;
	}
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(mk=0;mk<1<<mm;mk++)
		{
			for(j=0;j<mm;j++)
			{
				if(!(mk>>j&1))
				{
					mk2=mk&am[j]|am2[j];
					dp[1][mk2]+=dp[0][mk];
					if(dp[1][mk2]>=dv)
					{
						dp[1][mk2]-=dv;
					}
				}
			}
		}
		for(mk=0;mk<1<<mm;mk++)
		{
			dp[0][mk]=dp[1][mk];
			dp[1][mk]=0;
		}
	}
	for(mk=0;mk<1<<mm;mk++)
	{
		z+=dp[0][mk];
		if(z>=dv)
		{
			z-=dv;
		}
	}
	printf("%d\n",z);
}