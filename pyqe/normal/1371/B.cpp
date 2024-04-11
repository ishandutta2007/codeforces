#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long t,rr,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		k=min(n-1,d);
		printf("%lld\n",k*(k+1)/2+(d>=n));
	}
}