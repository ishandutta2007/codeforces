#include <bits/stdc++.h>

using namespace std;

long long n,a[300069];

int main()
{
	long long t,rr,i,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			mx=max(mx,a[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(a[i]==mx&&((i-1&&a[i-1]<a[i])||(i<n&&a[i+1]<a[i])))
			{
				printf("%lld\n",i);
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			printf("-1\n");
		}
	}
}