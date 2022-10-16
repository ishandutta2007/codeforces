#include <bits/stdc++.h>

using namespace std;

long long n,nn=0,a[200069];
map<long long,long long> fq;

int main()
{
	long long i,k,w=1e18,sm=0,z=-1e18;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(!fq[k])
		{
			nn++;
			a[nn]=k;
		}
		fq[k]++;
	}
	for(i=1;i<=nn;i++)
	{
		a[i]=fq[a[i]];
	}
	sort(a+1,a+nn+1,greater<long long>());
	for(i=1;i<=nn&&w;i++)
	{
		sm/=w;
		w=min(a[i],w/2);
		sm=(sm*2+1)*w;
		z=max(z,sm);
	}
	printf("%lld\n",z);
}