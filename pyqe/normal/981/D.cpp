#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=56,a[69];
bitset<69> dp[69];

int main()
{
	long long i,j,r,p,sm,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=ma-1;i+1;i--)
	{
		z|=1ll<<i;
		dp[0][0]=1;
		for(j=1;j<=n;j++)
		{
			for(r=1;r<=d;r++)
			{
				dp[j][r]=0;
			}
			sm=0;
			for(r=j-1;r+1;r--)
			{
				sm+=a[r+1];
				if((sm|z)==sm)
				{
					for(p=1;p<=d;p++)
					{
						dp[j][p]=(dp[j][p]||dp[r][p-1]);
					}
				}
			}
		}
		z^=(long long)!dp[n][d]<<i;
	}
	printf("%lld\n",z);
}