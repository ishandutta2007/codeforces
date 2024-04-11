#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long k,l,z,z2;
	
	scanf("%lld",&n);
	if(n<=2)
	{
		printf("-1\n");
		return 0;
	}
	if(n%2)
	{
		k=(n+1)/2;
		l=(n-1)/2;
		z=k*l*2;
		z2=k*k+l*l;
	}
	else
	{
		k=n/2;
		l=1;
		z=k*k-l*l;
		z2=k*k+l*l;
	}
	printf("%lld %lld\n",z,z2);
}