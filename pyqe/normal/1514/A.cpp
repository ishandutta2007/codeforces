#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,lh,rh,md,zz;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		bad=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			for(lh=1,rh=k;lh<=rh;)
			{
				md=(lh+rh)/2;
				if(md*md<=k)
				{
					zz=md;
					lh=md+1;
				}
				else
				{
					rh=md-1;
				}
			}
			bad|=zz*zz!=k;
		}
		if(bad)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}