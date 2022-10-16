#include <bits/stdc++.h>

using namespace std;

long long n,ttl=0,fq[2];

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		ttl+=k;
		fq[k%2]++;
	}
	printf("%lld\n",fq[ttl%2]);
}