#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,a[100069],fq[100069];

int main()
{
	long long i,k,l=0,z=0;
	bool bad=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		if(k!=a[nn])
		{
			nn++;
			a[nn]=k;
		}
		fq[nn]++;
	}
	for(i=1;i<=n;i++)
	{
		z+=min(fq[i],2ll);
		if(fq[i]>1)
		{
			z-=l&&!bad&&a[i]==a[l];
			l=i;
			bad=0;
		}
		bad|=a[i]!=a[l]&&a[i+1]!=a[l];
	}
	printf("%lld\n",z);
}