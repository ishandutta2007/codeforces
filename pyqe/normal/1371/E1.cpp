#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069],inf=1e18;

int main()
{
	long long i,mx=-inf,mn=inf;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		mx=max(mx,a[i]-i+1);
		if(i>=d)
		{
			mn=min(mn,a[i]-i+d);
		}
	}
	printf("%lld\n",max(mn-mx,0ll));
	for(i=mx;i<mn;i++)
	{
		printf("%lld%c",i," \n"[i==mn-1]);
	}
}