#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n*4;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n*4+1);
		bad=0;
		for(i=1;i<=n*4;i+=2)
		{
			if(a[i]!=a[i+1])
			{
				bad=1;
				break;
			}
		}
		for(i=3;i<=n*2;i+=2)
		{
			if(a[i]*a[n*4+1-i]!=a[1]*a[n*4])
			{
				bad=1;
				break;
			}
		}
		if(bad)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}
}