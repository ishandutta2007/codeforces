#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&k,&l,&n);
		printf("%lld\n",(n*(l+1)+k-3)/(k-1)+n);
	}
}