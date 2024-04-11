#include <bits/stdc++.h>

using namespace std;

long long n,fq[4];

int main()
{
	long long i,k,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
		mx=max(mx,fq[k]);
	}
	printf("%lld\n",n-mx);
}