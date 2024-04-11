#include <bits/stdc++.h>

using namespace std;

long long n,m;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld%lld",&n,&m,&k,&l);
		printf("%lld\n",max(k-1,n-k)+max(l-1,m-l));
	}
}