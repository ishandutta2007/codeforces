#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,gd=0,mx=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		gd=__gcd(gd,k);
		mx=max(mx,k);
	}
	if((mx/gd-n)%2==0)
	{
		printf("Bob\n");
	}
	else
	{
		printf("Alice\n");
	}
}