#include <bits/stdc++.h>

using namespace std;

long long n,m,d;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		z+=i<=n-m?k:d;
	}
	printf("%lld\n",z);
}