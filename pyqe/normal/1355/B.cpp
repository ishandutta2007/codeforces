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
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		c=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			c++;
			if(a[i]<=c)
			{
				c=0;
				z++;
			}
		}
		printf("%lld\n",z);
	}
}