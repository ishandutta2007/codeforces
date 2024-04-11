#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],dp[300069][3],d[300069];

int main()
{
	long long t,rr,i,j,jj,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",a+i,d+i);
		}
		z=1e18;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<3;j++)
			{
				dp[i][j]=1e18;
				for(jj=0;jj<3;jj++)
				{
					if(a[i-1]+jj==a[i]+j)
					{
						continue;
					}
					dp[i][j]=min(dp[i][j],dp[i-1][jj]);
				}
				dp[i][j]+=j*d[i];
				if(i==n)
				{
					z=min(z,dp[i][j]);
				}
			}
		}
		printf("%lld\n",z);
	}
}