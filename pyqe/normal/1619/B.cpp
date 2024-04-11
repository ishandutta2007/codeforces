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
		z=0;
		for(i=1;i*i<=n;i++,z++);
		for(i=1;i*i*i<=n;i++,z++);
		for(i=1;i*i*i*i*i*i<=n;i++,z--);
		printf("%lld\n",z);
	}
}