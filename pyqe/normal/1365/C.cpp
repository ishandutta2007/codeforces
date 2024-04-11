#include <bits/stdc++.h>

using namespace std;

long long n,pst[200069],fq[200069],inf=1e18;

int main()
{
	long long i,k,mx=-inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		pst[k]=i;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		k=(i+n-pst[k])%n;
		fq[k]++;
		mx=max(mx,fq[k]);
	}
	printf("%lld\n",mx);
}