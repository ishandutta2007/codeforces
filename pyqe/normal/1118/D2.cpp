#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

int main()
{
	long long i,lh,rh,md,zz=-1,sm;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+n,greater<long long>());
	lh=1;
	rh=n;
	for(;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		for(i=0;i<n;i++)
		{
			sm+=max(a[i]-i/md,0ll);
		}
		if(sm>=d)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}