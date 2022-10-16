#include <bits/stdc++.h>

using namespace std;

long long n,ttl=0,a[300069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		ttl+=a[i];
	}
	sort(a+1,a+n+1);
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld\n",ttl-a[n+1-k]);
	}
}