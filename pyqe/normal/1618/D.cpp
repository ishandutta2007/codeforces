#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i,c,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		z=0;
		for(i=1;i<=n-d*2;i++)
		{
			z+=a[i];
		}
		c=0;
		mx=0;
		for(i=n-d*2+1;i<=n;i++)
		{
			c=c*(a[i]==a[i-1])+1;
			mx=max(mx,c);
		}
		z+=max(mx-d,0ll);
		printf("%lld\n",z);
	}
}