#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,k,l;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&k,&l);
		printf("%lld\n",max(k,l)-(k+l-n)+1);
	}
}