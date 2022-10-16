#include <bits/stdc++.h>

using namespace std;

long long n,a[30069],inf=1e18;

int main()
{
	long long t,rr,i,ii,sm,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(ii=0;ii<2;ii++)
		{
			sm=0;
			l=inf;
			for(i=1;i<=n;i++)
			{
				sm+=max(a[i]-l,0ll);
				l=a[i];
				a[i]-=sm;
			}
			for(i=1;i<n+1-i;i++)
			{
				swap(a[i],a[n+1-i]);
			}
		}
		if(a[i]>=0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}