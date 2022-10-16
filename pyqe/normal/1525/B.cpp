#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			c+=a[i]==i;
		}
		if(c==n)
		{
			z=0;
		}
		else if(a[1]==1||a[n]==n)
		{
			z=1;
		}
		else if(!(a[1]==n&&a[n]==1))
		{
			z=2;
		}
		else
		{
			z=3;
		}
		printf("%lld\n",z);
	}
}