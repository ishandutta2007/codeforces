#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,e=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		if(a[i]>a[i%n+1])
		{
			if(e)
			{
				printf("-1\n");
				return 0;
			}
			e=i;
		}
	}
	e+=n*!e;
	printf("%lld\n",n-e);
}