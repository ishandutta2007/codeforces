#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][100069],dv,inf=1e9;
map<long long,long long> ls,fq;

int main()
{
	long long i,ii,k,z=-inf;
	
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld%lld",n+ii,&k);
		for(i=1;i<=n[ii];i++)
		{
			scanf("%lld",&a[ii][i]);
			fq[a[ii][i]]++;
			z=max(z,fq[a[ii][i]]);
		}
	}
	for(dv=1;dv<=inf;dv*=2)
	{
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n[ii];i++)
			{
				k=(a[ii][i]+dv*ii)%(dv*2);
				if(ls[k]<dv)
				{
					fq[k]=0;
					ls[k]=dv;
				}
				fq[k]++;
				z=max(z,fq[k]);
			}
		}
	}
	printf("%lld\n",z);
}