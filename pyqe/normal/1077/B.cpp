#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<100069> a;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
	}
	for(i=2;i<=n-1;i++)
	{
		if(!a[i]&&a[i-1]&&a[i+1])
		{
			a[i+1]=0;
			z++;
		}
	}
	printf("%lld\n",z);
}