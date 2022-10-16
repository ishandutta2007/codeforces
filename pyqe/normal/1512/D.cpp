#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],zs;

int main()
{
	long long t,rr,i,sm,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		for(i=1;i<=n+2;i++)
		{
			scanf("%lld",a+i);
			sm+=a[i];
		}
		sort(a+1,a+n+3);
		for(i=1;i<=n+2;i++)
		{
			if(sm-a[i]==a[n+2-(i==n+2)]*2)
			{
				break;
			}
		}
		if(i>n+2)
		{
			printf("-1\n");
			continue;
		}
		p=i;
		zs=0;
		for(i=1;i<=n+2;i++)
		{
			if(i!=p&&zs<n)
			{
				zs++;
				printf("%lld%c",a[i]," \n"[zs==n]);
			}
		}
	}
}