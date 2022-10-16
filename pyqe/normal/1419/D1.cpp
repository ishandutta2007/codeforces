#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,lh,rh,md,zz,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(lh=0,rh=(n-1)/2;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=0;i<=md;i++)
		{
			if(a[n-md+i]<=max(a[i],a[i+1]*(i<md)))
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz);
	for(i=1;i<=n;i++)
	{
		if(i<=zz*2+1)
		{
			z=a[i/2+(n-zz)*(i%2)];
		}
		else
		{
			z=a[i-zz-1];
		}
		printf("%lld%c",z," \n"[i==n]);
	}
}