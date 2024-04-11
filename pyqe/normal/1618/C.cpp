#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,ii,gd,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=0;
		for(ii=0;ii<2;ii++)
		{
			gd=0;
			for(i=1+ii;i<=n;i+=2)
			{
				gd=__gcd(gd,a[i]);
			}
			for(i=1+!ii;i<=n;i+=2)
			{
				if(a[i]%gd==0)
				{
					break;
				}
			}
			if(i>n)
			{
				z=gd;
				break;
			}
		}
		printf("%lld\n",z);
	}
}