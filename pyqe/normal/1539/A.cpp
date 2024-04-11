#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

long long tri(long long x)
{
	return x*(x-1)/2;
}

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		printf("%lld\n",d/m*max(n-d/m,0ll)+tri(min(d/m,n)));
	}
}