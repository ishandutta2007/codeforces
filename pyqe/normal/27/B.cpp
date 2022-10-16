#include <bits/stdc++.h>

using namespace std;

long long n,fq[100069],fq2[100069];

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n*(n-1)/2-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		fq[k]++;
		fq[l]++;
		fq2[k]++;
	}
	for(i=1;i<=n;i++)
	{
		if(fq[i]!=n-1)
		{
			k=l;
			l=i;
		}
	}
	if(fq2[k]<fq2[l])
	{
		swap(k,l);
	}
	printf("%lld %lld\n",k,l);
}