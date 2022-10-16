#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,z=-1e18;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z=max(z,min(k-1,1000000-k));
	}
	printf("%lld\n",z);
}