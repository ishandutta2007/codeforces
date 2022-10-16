#include <bits/stdc++.h>

using namespace std;

long long n,nv=0,lz,a[200069],vi[200069];

int main()
{
	long long t,rr,i,ky,k,l,z=0;
	
	scanf("%lld%lld",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		z+=a[i];
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&ky,&k);
		if(ky==1)
		{
			scanf("%lld",&l);
			if(vi[k]<nv)
			{
				vi[k]=nv;
				a[k]=lz;
			}
			z+=l-a[k];
			a[k]=l;
		}
		else
		{
			z=k*n;
			nv++;
			lz=k;
		}
		printf("%lld\n",z);
	}
}