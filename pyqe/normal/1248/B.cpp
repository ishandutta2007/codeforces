#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,z=0,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		c+=a[i];
		if(i==n/2||i==n)
		{
			z+=c*c;
			c=0;
		}
	}
	printf("%lld\n",z);
}