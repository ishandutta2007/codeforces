#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			z+=a[i]*(i<n);
		}
		c=0;
		for(i=n-1;i;i--)
		{
			if(!a[i])
			{
				c++;
			}
			else
			{
				z+=c;
				c=0;
			}
		}
		printf("%lld\n",z);
	}
}