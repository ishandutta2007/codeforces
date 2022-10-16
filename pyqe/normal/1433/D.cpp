#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,k,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		p=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			if(a[i]!=a[1])
			{
				p=i;
			}
		}
		if(p==-1)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		for(i=2;i<=n;i++)
		{
			if(a[i]!=a[1])
			{
				k=1;
			}
			else
			{
				k=p;
			}
			printf("%lld %lld\n",i,k);
		}
	}
}