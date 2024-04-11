#include <bits/stdc++.h>

using namespace std;

long long n,d,a[200069];

int main()
{
	long long i,lh,rh,md,zz;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(lh=0,rh=n/2;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=md;i++)
		{
			if(a[n-md+i]-a[i]<d)
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
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