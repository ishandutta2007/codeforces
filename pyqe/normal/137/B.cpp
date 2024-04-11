#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> vtd;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		vtd[k]=1;
	}
	for(i=1;i<=n;i++)
	{
		z+=!vtd[i];
	}
	printf("%lld\n",z);
}