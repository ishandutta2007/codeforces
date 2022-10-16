#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][100069],ps[2][100069],inf=1e18;

int main()
{
	long long i,ii,k,p,sm,z=inf;
	
	scanf("%lld%lld",n,n+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n[ii];i++)
		{
			scanf("%lld",&a[ii][i]);
		}
		sort(a[ii]+1,a[ii]+n[ii]+1);
		for(i=1;i<=n[ii];i++)
		{
			ps[ii][i]=ps[ii][i-1]+a[ii][i];
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n[ii];i++)
		{
			k=a[ii][i];
			sm=0;
			p=upper_bound(a[0]+1,a[0]+n[0]+1,k)-a[0];
			p--;
			sm+=k*p-ps[0][p];
			p=lower_bound(a[1]+1,a[1]+n[1]+1,k)-a[1];
			sm+=ps[1][n[1]]-ps[1][p-1]-k*(n[1]+1-p);
			z=min(z,sm);
		}
	}
	printf("%lld\n",z);
}