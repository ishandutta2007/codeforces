#include <bits/stdc++.h>

using namespace std;

long long n,d,inf=1e18;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=inf;
		for(i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				if(n/i<=d)
				{
					z=min(z,i);
				}
				if(i<=d)
				{
					z=min(z,n/i);
				}
			}
		}
		printf("%lld\n",z);
	}
}