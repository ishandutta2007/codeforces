#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[2][100069];

int main()
{
	long long t,rr,i,ii,jj,sm,mn,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
			}
		}
		z=0;
		for(i=2;i<=n;i++)
		{
			mn=inf;
			for(ii=0;ii<2;ii++)
			{
				sm=0;
				for(jj=0;jj<2;jj++)
				{
					sm+=abs(a[jj][i-1]-a[jj^ii][i]);
				}
				mn=min(mn,sm);
			}
			z+=mn;
		}
		printf("%lld\n",z);
	}
}