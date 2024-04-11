#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,a,b,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&a,&b,&k);
		printf("%lld\n",a*((k-1)/2+1)-b*(k/2));
	}
}