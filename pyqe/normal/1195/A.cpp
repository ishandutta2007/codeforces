#include <bits/stdc++.h>

using namespace std;

long long n,m;
bitset<100069> fq;

int main()
{
	long long i,k,z;
	bool bad=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]=!fq[k];
	}
	z=n;
	for(i=1;i<=m;i++)
	{
		if(fq[i])
		{
			z-=bad;
			bad^=1;
		}
	}
	printf("%lld\n",z);
}