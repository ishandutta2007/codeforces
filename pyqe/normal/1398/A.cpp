#include <bits/stdc++.h>

using namespace std;

long long n,a[50069];

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
		if(a[1]+a[2]<=a[n])
		{
			printf("1 2 %lld\n",n);
		}
		else
		{
			printf("-1\n");
		}
	}
}