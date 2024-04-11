#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sq[100069];

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
		if(n%2)
		{
			printf("NO\n");
			continue;
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n/2;i++)
		{
			sq[i*2-1]=a[i];
		}
		for(i=1;i<=n/2;i++)
		{
			sq[i*2]=a[n/2+i];
		}
		for(i=1;i<=n;i++)
		{
			if(sq[i]==sq[i+1])
			{
				break;
			}
		}
		if(i>n)
		{
			printf("YES\n");
			for(i=1;i<=n;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==n]);
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}