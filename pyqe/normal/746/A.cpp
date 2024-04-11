#include <bits/stdc++.h>

using namespace std;

long long inf=1e18;

int main()
{
	long long i,k,z=inf;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",&k);
		z=min(z,k>>i);
	}
	printf("%lld\n",z*7);
}