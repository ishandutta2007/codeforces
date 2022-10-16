#include <bits/stdc++.h>

using namespace std;

long long n,fq[31];

int main()
{
	long long t,rr,i,k,c,z=0;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<31;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			for(c=0;k;k/=2,c++);
			fq[c]++;
		}
		z=0;
		for(i=0;i<31;i++)
		{
			z+=fq[i]*(fq[i]-1)/2;
		}
		printf("%lld\n",z);
	}
}