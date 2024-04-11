#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i,sm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		sm=0;
		for(i=1;i<=n;i++)
		{
			sm+=a[i];
			if(sm==d)
			{
				swap(a[i],a[i+1]);
				break;
			}
		}
		if(i!=n)
		{
			printf("YES\n");
			for(i=1;i<=n;i++)
			{
				printf("%lld%c",a[i]," \n"[i==n]);
			}
		}
		else
		{
			printf("NO\n");
		}
	}
}