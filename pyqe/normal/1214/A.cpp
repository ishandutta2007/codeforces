#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,l,mn=1e18;
	
	scanf("%lld%lld%lld",&n,&k,&l);
	l*=5;
	for(i=0;i*l<=n;i++)
	{
		mn=min(mn,(n-i*l)%k);
	}
	printf("%lld\n",mn);
}