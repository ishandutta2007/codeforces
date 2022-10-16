#include <bits/stdc++.h>

using namespace std;

long long n,a[4];

int main()
{
	long long t,rr,i,k,mk;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<4;i++)
		{
			scanf("%lld",a+i);
		}
		for(mk=0;mk<1ll<<4;mk++)
		{
			for(i=0;i<4;i++)
			{
				k=a[i]-(mk>>i&1)-(mk>>(i+1)%4&1);
				if(k<0||k>n-2)
				{
					break;
				}
			}
			if(i>=4)
			{
				break;
			}
		}
		if(mk<1ll<<4)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}