#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t,rr,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&k);
		printf("%lld\n",k+k/2*2+k/3*2);
	}
}