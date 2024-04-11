#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long i,k,mn=inf;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		mn=min(mn,k);
	}
	printf("%lld\n",mn+n/2);
}