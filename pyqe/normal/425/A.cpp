#include <bits/stdc++.h>

using namespace std;

long long n,d,nn[2],a[269],as[2][269],inf=1e18;

int main()
{
	long long i,j,r,ii,sm,e,z=-inf;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			sm=0;
			for(ii=0;ii<2;ii++)
			{
				nn[ii]=0;
			}
			for(r=1;r<=n;r++)
			{
				e=r>=i&&r<=j;
				sm+=a[r]*e;
				nn[e]++;
				as[e][nn[e]]=a[r];
			}
			sort(as[0]+1,as[0]+nn[0]+1,greater<long long>());
			sort(as[1]+1,as[1]+nn[1]+1);
			for(r=1;r<=min(min(nn[0],nn[1]),d);r++)
			{
				sm+=max(as[0][r]-as[1][r],0ll);
			}
			z=max(z,sm);
		}
	}
	printf("%lld\n",z);
}