#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,a[200069],as[200069];

int main()
{
	long long i,j,ii,k,p,sm,z=1e18;
	
	srand(time(NULL));
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<20;i++)
	{
		p=(rand()<<15|rand()+n-1)%n+1;
		for(ii=a[p]-1;ii<=a[p]+1;ii++)
		{
			k=ii;
			for(j=2;j*j<=k;j++)
			{
				if(k%j==0)
				{
					nn++;
					as[nn]=j;
					for(;k%j==0;k/=j);
				}
			}
			if(k>1)
			{
				nn++;
				as[nn]=k;
			}
		}
	}
	sort(as+1,as+nn+1);
	for(i=1;i<=nn;i++)
	{
		if(i==1||as[i]>as[i-1])
		{
			sm=0;
			for(j=1;j<=n;j++)
			{
				k=a[j]/as[i];
				sm+=min(abs(a[j]-(k+!k)*as[i]),(k+1)*as[i]-a[j]);
			}
			z=min(z,sm);
		}
	}
	printf("%lld\n",z);
}