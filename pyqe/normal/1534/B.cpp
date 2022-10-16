#include <bits/stdc++.h>

using namespace std;

long long n,a[400069];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		a[n+1]=0;
		z=0;
		for(i=1;i<=n+1;i++)
		{
			z+=abs(a[i]-a[i-1]);
			if(i<=n)
			{
				k=max(a[i-1],a[i+1]);
				z-=max(a[i]-k,0ll);
			}
		}
		printf("%lld\n",z);
	}
}