#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

int main()
{
	long long t,rr,i,p;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			p=lower_bound(a+1,a+n+1,a[i]-d)-a;
			if(p<=n&&a[p]==a[i]-d)
			{
				break;
			}
		}
		if(i<=n)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}