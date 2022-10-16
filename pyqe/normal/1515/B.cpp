#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,ii,lh,rh,md,zz;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			if(n%2)
			{
				ii=2;
				break;
			}
			n/=2;
			for(lh=1,rh=n;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(md*md<=n)
				{
					zz=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			if(zz*zz==n)
			{
				break;
			}
		}
		if(ii<2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}