#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		n/=2;
		if(n%2)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			printf("%lld ",i*2);
		}
		for(i=1;i<=n-1;i++)
		{
			printf("%lld ",i*2-1);
		}
		printf("%lld\n",n*3-1);
	}
}