#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,i,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&k,&l);
		printf("%lld\n",min(abs(k-l)+m,n-1));
	}
}