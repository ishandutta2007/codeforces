#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,lh,rh,md,zz;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(lh=0,rh=n-1;lh<=rh;)
	{
		md=(lh+rh)/2;
		for(i=1;i<=md;i++)
		{
			if(a[i]==a[i+n-md])
			{
				break;
			}
		}
		if(i>md)
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