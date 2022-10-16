#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[2][200069],mn[2][2];

int main()
{
	long long t,rr,i,ii,jj,sm,z;
	
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
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				mn[ii][jj]=inf;
				for(i=1;i<=n;i++)
				{
					mn[ii][jj]=min(mn[ii][jj],abs(a[ii][1+(n-1)*jj]-a[!ii][i]));
				}
			}
		}
		z=inf;
		for(ii=0;ii<2;ii++)
		{
			sm=0;
			for(jj=0;jj<2;jj++)
			{
				sm+=min(abs(a[0][1+(n-1)*jj]-a[1][1+(n-1)*(ii^jj)]),mn[0][jj]+mn[1][ii^jj]);
			}
			z=min(z,sm);
		}
		printf("%lld\n",z);
	}
}