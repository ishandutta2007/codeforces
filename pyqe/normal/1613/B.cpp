#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(i=2;i<=n/2+1;i++)
		{
			printf("%lld %lld\n",a[i],a[1]);
		}
	}
}