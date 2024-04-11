#include <bits/stdc++.h>

using namespace std;

long long n,d,d2,sq[100069];

int main()
{
	long long t,rr,i,mn,e;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&d2);
		if(d+d2>n-2||abs(d-d2)>1)
		{
			printf("-1\n");
			continue;
		}
		mn=0;
		e=d2>d;
		for(i=1;i<=n;i++)
		{
			if(i>1)
			{
				if(!e)
				{
					sq[i]=i+mn-1;
				}
				else
				{
					sq[i]=mn-1;
					mn--;
				}
				if(i<=d+d2+1)
				{
					e^=1;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",sq[i]-mn+1," \n"[i==n]);
		}
	}
}