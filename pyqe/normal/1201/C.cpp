#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

int main()
{
	long long i,lh,rh,md,zz,sm;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(lh=0,rh=2e9;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		for(i=(n+1)/2;i<=n;i++)
		{
			sm+=max(md-a[i],0ll);
		}
		if(sm<=d)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz);
}