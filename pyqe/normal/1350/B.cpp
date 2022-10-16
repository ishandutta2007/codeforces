#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dp[100069],inf=1e18;

int main()
{
	long long t,rr,i,j,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			dp[i]=1;
		}
		z=-inf;
		for(i=1;i<=n;i++)
		{
			for(j=i*2;j<=n;j+=i)
			{
				if(a[j]>a[i])
				{
					dp[j]=max(dp[j],dp[i]+1);
				}
			}
			z=max(z,dp[i]);
		}
		printf("%lld\n",z);
	}
}