#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,sm=0;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld",&k);
		sm+=k;
	}
	printf("%lld\n",n*(n+1)/2-sm);
}