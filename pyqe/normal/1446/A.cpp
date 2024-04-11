#include <bits/stdc++.h>

using namespace std;

long long n,d,sq[200069],zs;

int main()
{
	long long t,rr,i,sm,k;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		zs=0;
		sm=0;
		bad=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(k<=d)
			{
				if(k*2>=d)
				{
					zs=1;
					sq[zs]=i;
					bad=1;
				}
				else if(!bad)
				{
					sm+=k;
					zs++;
					sq[zs]=i;
					if(sm*2>=d)
					{
						bad=1;
					}
				}
			}
		}
		if(!bad)
		{
			zs=-1;
		}
		printf("%lld\n",zs);
		for(i=1;i<=zs;i++)
		{
			printf("%lld%c",sq[i]," \n"[i==zs]);
		}
	}
}