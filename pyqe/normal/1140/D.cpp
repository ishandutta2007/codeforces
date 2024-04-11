#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=3;i<=n;i++)
	{
		z+=(i-1)*i;
	}
	printf("%lld\n",z);
}