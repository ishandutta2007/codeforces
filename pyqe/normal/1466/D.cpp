#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[100069],as[100069];
bitset<100069> vtd;

int main()
{
	long long t,rr,i,ii,k,l,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			z+=a[i];
			vtd[i]=0;
		}
		nn=0;
		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld",&k,&l);
			for(ii=0;ii<2;ii++)
			{
				if(vtd[k])
				{
					nn++;
					as[nn]=a[k];
				}
				vtd[k]=1;
				swap(k,l);
			}
		}
		sort(as+1,as+nn+1,greater<long long>());
		for(i=0;i<=nn;i++)
		{
			z+=as[i];
			printf("%lld%c",z," \n"[i==nn]);
		}
	}
}