#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k,gd;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		gd=__gcd(k,100-k);
		printf("%lld\n",100ll/gd);
	}
}