#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n;

int main()
{
	long long t,rr,i,lm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		lm=1;
		z=n%dv;
		for(i=1;lm<=n;i++)
		{
			lm=lm/__gcd(lm,i)*i;
			z=(z+n/lm)%dv;
		}
		printf("%lld\n",z);
	}
}