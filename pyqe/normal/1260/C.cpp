#include <bits/stdc++.h>

using namespace std;

long long d;

int main()
{
	long long t,rr,k,l,gd;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&d);
		if(k<l)
		{
			swap(k,l);
		}
		gd=__gcd(k,l);
		k/=gd;
		l/=gd;
		if(d<=(k-2)/l+1)
		{
			printf("REBEL\n");
		}
		else
		{
			printf("OBEY\n");
		}
	}
}