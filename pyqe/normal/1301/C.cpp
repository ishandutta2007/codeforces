#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,k,rm;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		k=(n-m)/(m+1);
		rm=(n-m)%(m+1);
		printf("%lld\n",n*(n+1)/2-(k+1)*(k+2)/2*rm-k*(k+1)/2*(m+1-rm));
	}
}