#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z+=k;
	}
	printf("%lld\n",z);
}