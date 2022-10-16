#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		z=(1ll<<n)+((1ll<<n/2-1)-1)*2-(((1ll<<n/2)-1)<<n/2);
		printf("%lld\n",z);
	}
}