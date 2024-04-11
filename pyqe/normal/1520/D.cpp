#include <bits/stdc++.h>

using namespace std;

long long n,fq[400069];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<=n*2;i++)
		{
			fq[i]=0;
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			z+=fq[k-i+n];
			fq[k-i+n]++;
		}
		printf("%lld\n",z);
	}
}