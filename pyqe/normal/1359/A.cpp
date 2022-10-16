#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long t,rr,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		z=min(n/d,m);
		z-=(m-z+d-2)/(d-1);
		printf("%lld\n",z);
	}
}