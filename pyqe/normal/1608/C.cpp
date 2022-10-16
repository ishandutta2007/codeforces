#include <bits/stdc++.h>

using namespace std;

long long n,a[2][100069],as[100069],dp[100069];

int main()
{
	long long t,rr,i,ii;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
				as[i]=a[ii][i];
			}
			sort(as+1,as+n+1);
			for(i=1;i<=n;i++)
			{
				a[ii][i]=lower_bound(as+1,as+n+1,a[ii][i])-as;
			}
		}
		for(i=1;i<=n;i++)
		{
			dp[i]=i;
		}
		for(i=1;i<=n;i++)
		{
			dp[a[0][i]]=a[1][i];
		}
		for(i=2;i<=n;i++)
		{
			dp[i]=max(dp[i],dp[i-1]);
		}
		for(i=n;i;i--)
		{
			dp[i]=dp[dp[i]];
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld",(long long)(dp[a[0][i]]==n));
		}
		printf("\n");
	}
}