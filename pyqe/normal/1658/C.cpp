#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,e,tg;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		bad=0;
		e=-1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			if(a[i]==1)
			{
				bad|=e!=-1;
				e=i;
			}
		}
		if(bad||e==-1)
		{
			printf("NO\n");
			continue;
		}
		for(i=0;i<n-1;i++)
		{
			tg=e%n+1;
			if(a[tg]-a[e]>1)
			{
				break;
			}
			e=tg;
		}
		if(i>=n-1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}