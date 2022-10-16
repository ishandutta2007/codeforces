#include <bits/stdc++.h>

using namespace std;

long long n,ttl,a[200069];
map<long long,long long> fq;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			ttl+=a[i];
		}
		ttl*=2;
		if(ttl%n)
		{
			printf("0\n");
			continue;
		}
		ttl/=n;
		fq.clear();
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=fq[ttl-a[i]];
			fq[a[i]]++;
		}
		printf("%lld\n",z);
	}
}