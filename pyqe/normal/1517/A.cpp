#include <bits/stdc++.h>

using namespace std;

const long long d=2050;
long long n;

int main()
{
	long long t,rr,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		if(n%d)
		{
			printf("-1\n");
			continue;
		}
		n/=d;
		for(z=0;n;z+=n%10,n/=10);
		printf("%lld\n",z);
	}
}