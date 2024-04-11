#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],dp[200069];

int main()
{
	long long t,rr,i,ii,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			dp[i]=0;
		}
		sort(a+1,a+n+1);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
		}
		for(ii=0;ii<2;ii++)
		{
			for(i=n;i;i--)
			{
				k=lower_bound(a+1,a+n+1,a[i]-d)-a;
				dp[i]=dp[k-1]+i-k+1;
			}
			for(i=1;i<=n;i++)
			{
				dp[i]=max(dp[i],dp[i-1]);
			}
		}
		printf("%lld\n",dp[n]);
	}
}