#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,c=0,l=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		c++;
		if(i==n||a[i]!=a[i+1])
		{
			z=max(z,min(c,l)*2);
			l=c;
			c=0;
		}
	}
	printf("%lld\n",z);
}