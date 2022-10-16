#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],lb[100069],rb[100069],dp[100069],inf=1e18;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",lb+i);
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",rb+i);
			if(lb[i]>rb[i])
			{
				swap(lb[i],rb[i]);
			}
			if(i-1)
			{
				dp[i]=rb[i]-lb[i]+2;
				if(lb[i]<rb[i])
				{
					dp[i]=max(dp[i],dp[i-1]+a[i-1]-1-(rb[i]-lb[i])+2);
				}
				z=max(z,dp[i]+a[i]-1);
			}
			else
			{
				dp[i]=-inf;
			}
		}
		printf("%lld\n",z);
	}
}