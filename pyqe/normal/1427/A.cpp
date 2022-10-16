#include <bits/stdc++.h>

using namespace std;

long long n,ttl,a[100069];

int main()
{
	long long t,rr,i;
	
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
		if(ttl>0)
		{
			sort(a+1,a+n+1,greater<long long>());
		}
		else if(ttl<0)
		{
			sort(a+1,a+n+1);
		}
		else
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",a[i]," \n"[i==n]);
		}
	}
}