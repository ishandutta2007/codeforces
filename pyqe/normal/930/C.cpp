#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],lis[100069],dp[100069],inf=1e18;

int main()
{
	long long i,ii,u,k,l,p,z=-inf;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&k,&l);
		a[k]++;
		a[l+1]--;
	}
	for(i=1;i<=m;i++)
	{
		a[i]+=a[i-1];
	}
	for(ii=0;ii<2;ii++)
	{
		u=!ii*2-1;
		for(i=1;i<=m;i++)
		{
			lis[i]=inf;
		}
		for(i=1+(m-1)*ii;i&&i<=m;i+=u)
		{
			p=upper_bound(lis+1,lis+m+1,a[i])-lis;
			lis[p]=a[i];
			dp[i]+=p;
		}
	}
	for(i=1;i<=m;i++)
	{
		z=max(z,dp[i]-1);
	}
	printf("%lld\n",z);
}