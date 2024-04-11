#include <bits/stdc++.h>

using namespace std;

long long n,a[10];

int main()
{
	long long t,rr,i,mk,mk2,mk3,sm,sm2;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
		}
		bad=0;
		for(mk=1;!bad&&mk<1ll<<n;mk++)
		{
			sm=0;
			for(i=0;i<n;i++)
			{
				sm+=abs(a[i])*(mk>>i&1);
			}
			mk2=(1ll<<n)-1^mk;
			for(mk3=mk2;1;mk3=mk3-1&mk2)
			{
				sm2=0;
				for(i=0;i<n;i++)
				{
					sm2+=abs(a[i])*(mk3>>i&1);
				}
				if(sm2==sm)
				{
					bad=1;
					break;
				}
				if(!mk3)
				{
					break;
				}
			}
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