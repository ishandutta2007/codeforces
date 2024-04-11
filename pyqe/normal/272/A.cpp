#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,sm=0,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		sm=(sm+k)%(n+1);
	}
	for(i=1;i<=5;i++)
	{
		z+=(sm+i)%(n+1)!=1;
	}
	printf("%lld\n",z);
}