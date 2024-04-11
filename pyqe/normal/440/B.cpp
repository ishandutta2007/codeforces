#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,sm=0,c=0,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sm+=a[i];
	}
	for(i=1;i<=n;i++)
	{
		z+=abs(c);
		c+=a[i]-sm/n;
	}
	printf("%lld\n",z);
}