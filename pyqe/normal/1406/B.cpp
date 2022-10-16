#include <bits/stdc++.h>

using namespace std;

long long n,nn[2],a[2][100069],inf=1e18;

int main()
{
	long long t,rr,i,j,ii,k,ml,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			nn[ii]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			nn[k<0]++;
			a[k<0][nn[k<0]]=abs(k);
		}
		for(ii=0;ii<2;ii++)
		{
			sort(a[ii]+1,a[ii]+nn[ii]+1);
		}
		z=-inf;
		for(i=max(5-nn[0],0ll);i<=min(nn[1],5ll);i++)
		{
			if(i%2==0)
			{
				ml=1;
				for(j=nn[0];j>nn[0]-(5-i);j--)
				{
					ml*=a[0][j];
				}
				for(j=nn[1];j>nn[1]-i;j--)
				{
					ml*=a[1][j];
				}
			}
			else
			{
				ml=-1;
				for(j=1;j<=5-i;j++)
				{
					ml*=a[0][j];
				}
				for(j=1;j<=i;j++)
				{
					ml*=a[1][j];
				}
			}
			z=max(z,ml);
		}
		printf("%lld\n",z);
	}
}