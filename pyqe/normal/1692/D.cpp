#include <bits/stdc++.h>

using namespace std;

const long long d=60,d2=24;
long long n,m;
bitset<1469> vtd;

int main()
{
	long long t,rr,k,l,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld %c%lld%lld",&k,&ch,&l,&m);
		n=k*60+l;
		vtd.reset();
		z=0;
		for(;!vtd[n];n=(n+m)%(d*d2))
		{
			vtd[n]=1;
			z+=n%d%10==n/d/10&&n%d/10==n/d%10;
		}
		printf("%lld\n",z);
	}
}