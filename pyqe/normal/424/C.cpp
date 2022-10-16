#include <bits/stdc++.h>

using namespace std;

long long n,ps[1000069];

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		ps[i]=ps[i-1]^i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		z^=k^ps[i-1]*((n+1)/i%2)^ps[max((n+1)%i-1,0ll)];
	}
	printf("%lld\n",z);
}