#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=100,a[100069],dp[100069],inf=1e18;

int main()
{
	long long t,rr,i,j,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=inf;
		for(i=1;i<=ma;i++)
		{
			l=0;
			for(j=1;j<=n;j++)
			{
				dp[j]=inf;
				if(a[j]!=i)
				{
					l=j;
				}
				dp[j]=min(dp[l],dp[max(j-d,0ll)]+1);
			}
			z=min(z,dp[n]);
		}
		printf("%lld\n",z);
	}
}