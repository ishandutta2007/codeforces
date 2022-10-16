#include <bits/stdc++.h>

using namespace std;

long long n,a[1069];

int main()
{
	long long i,z=0,c=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	a[n+1]=1001;
	for(i=1;i<=n;i++)
	{
		if(a[i-1]==a[i]-1&&a[i+1]==a[i]+1)
		{
			c++;
			z=max(z,c);
		}
		else
		{
			c=0;
		}
	}
	printf("%lld\n",z);
}