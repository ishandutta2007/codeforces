#include <bits/stdc++.h>

using namespace std;

long long n,a[2];

int main()
{
	long long ii,z=0;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",a+ii);
		z+=a[ii]/n;
	}
	for(ii=0;ii<2;ii++)
	{
		if(a[ii]%n&&a[!ii]/n==0)
		{
			z=-1;
		}
	}
	printf("%lld\n",z);
}