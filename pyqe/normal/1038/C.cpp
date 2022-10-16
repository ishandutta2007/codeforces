#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long i,ii,z=0;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+n*ii+i);
			z+=a[n*ii+i]*!ii;
		}
	}
	sort(a+1,a+n*2+1,greater<long long>());
	for(i=2;i<=n*2;i+=2)
	{
		z-=a[i];
	}
	printf("%lld\n",z);
}