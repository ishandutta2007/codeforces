#include <bits/stdc++.h>

using namespace std;

long long n,m,d,d2;

int main()
{
	long long t,rr;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&d,&d2,&m);
		printf("%lld\n",n/m+n/m/d*d2);
	}
}