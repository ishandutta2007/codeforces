#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069],inf=1e18;

int main()
{
	long long t,rr,i,mn,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		mn=inf;
		mx=-inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
		}
		for(i=1;i<=n;i++)
		{
			if(d%2)
			{
				a[i]=mx-a[i];
			}
			else
			{
				a[i]-=mn;
			}
			printf("%lld%c",a[i]," \n"[i==n]);
		}
	}
}