#include <bits/stdc++.h>
 
using namespace std;
 
long long n;
double am[18][18],dp[1<<18][18];
 
int main()
{
	long long i,j,mk;
	double mx=-1e18;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&am[i][j]);
		}
	}
	for(mk=0;mk<1<<n;mk++)
	{
		for(i=0;i<n;i++)
		{
			if(mk>>i&1)
			{
				if(mk^1<<i)
				{
					dp[mk][i]=-1e18;
					for(j=0;j<n;j++)
					{
						if(j!=i&&(mk>>j&1))
						{
							dp[mk][i]=max(dp[mk][i],dp[mk^1<<j][i]*am[i][j]+dp[mk^1<<i][j]*am[j][i]);
						}
					}
				}
				else
				{
					dp[mk][i]=!i;
				}
				if(mk==(1<<n)-1)
				{
					mx=max(mx,dp[mk][i]);
				}
			}
		}
	}
	printf("%.15lf\n",mx);
}