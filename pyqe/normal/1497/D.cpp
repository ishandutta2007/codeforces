#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[5069],wg[5069],dp[5069],ca[5069];

int main()
{
	long long t,rr,i,j,mx,z=0;
	
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
			scanf("%lld",wg+i);
		}
		for(i=1;i<=n;i++)
		{
			dp[i]=0;
			ca[i]=0;
			for(j=i-1;j;j--)
			{
				if(a[j]!=a[i])
				{
					ca[j]=dp[j]+abs(wg[j]-wg[i]);
					dp[i]=max(dp[i],ca[j]);
				}
			}
			mx=0;
			for(j=i-1;j;j--)
			{
				if(a[j]!=a[i])
				{
					dp[j]=max(dp[j],mx+abs(wg[j]-wg[i]));
					mx=max(mx,ca[j]);
				}
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			z=max(z,dp[i]);
		}
		printf("%lld\n",z);
	}
}