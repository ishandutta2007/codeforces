#include <bits/stdc++.h>

using namespace std;

long long n,a[1069];

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(z=0;1;)
		{
			for(i=1;i<n;i++)
			{
				if(a[i]>a[i+1])
				{
					break;
				}
			}
			if(i>=n)
			{
				break;
			}
			z++;
			for(i=1;i<n;i++)
			{
				if(i%2==z%2)
				{
					if(a[i]>a[i+1])
					{
						swap(a[i],a[i+1]);
					}
				}
			}
		}
		printf("%lld\n",z);
	}
}