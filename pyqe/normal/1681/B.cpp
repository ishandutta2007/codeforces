#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i,k,sz,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
		}
		scanf("%lld",&sz);
		sm=0;
		for(i=0;i<sz;i++)
		{
			scanf("%lld",&k);
			sm+=k;
		}
		printf("%lld\n",a[sm%n]);
	}
}