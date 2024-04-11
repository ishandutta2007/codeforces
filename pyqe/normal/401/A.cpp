#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k,sm=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		sm+=k;
	}
	printf("%lld\n",(abs(sm)+d-1)/d);
}