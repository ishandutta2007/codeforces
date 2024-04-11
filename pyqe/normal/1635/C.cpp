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
		for(i=1;i<n;i++)
		{
			if(a[i]>a[i+1])
			{
				break;
			}
		}
		if(i>=n)
		{
			printf("0\n");
			continue;
		}
		if(a[n-1]>a[n]||a[n]<0)
		{
			printf("-1\n");
			continue;
		}
		printf("%lld\n",n-2);
		for(i=1;i<=n-2;i++)
		{
			printf("%lld %lld %lld\n",i,n-1,n);
		}
	}
}