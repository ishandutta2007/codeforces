#include <bits/stdc++.h>

using namespace std;

long long n,m,z,inf=1e18;

void chk(long long x)
{
	long long k;
	
	for(k=n;k%x==0;k/=x);
	for(;n%(k*x)==0&&k*x%m;k*=x);
	z=max(z,k);
}

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		if(n%m)
		{
			z=n;
		}
		else
		{
			z=-inf;
			for(i=1;i*i<=m;i++)
			{
				if(m%i==0)
				{
					if(i-1)
					{
						chk(i);
					}
					chk(m/i);
				}
			}
		}
		printf("%lld\n",z);
	}
}