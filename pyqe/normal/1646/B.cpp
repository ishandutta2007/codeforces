#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],ps[200069];

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
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			ps[i]=ps[i-1]+a[i];
		}
		for(i=1;i+1<=n-i;i++)
		{
			if(ps[i+1]<ps[n]-ps[n-i])
			{
				break;
			}
		}
		if(i+1<=n-i)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}