#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],inf=1e18;

int main()
{
	long long t,rr,i,sm,mn,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			sm+=abs(a[i]-a[i-1])*(i>1);
		}
		mn=inf;
		for(i=1;i<=n;i++)
		{
			w=-abs(a[i]-a[i-1])*(i>1)-abs(a[i]-a[i+1])*(i<n)+abs(a[i+1]-a[i-1])*(i>1&&i<n);
			mn=min(mn,w);
		}
		printf("%lld\n",sm+mn);
	}
}