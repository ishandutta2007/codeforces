#include <bits/stdc++.h>

using namespace std;

const long long ma=100;
long long n,fq[169];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<=ma;i++)
		{
			fq[i]=0;
		}
		fq[0]=1;
		z=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[abs(k)]++;
			z+=fq[abs(k)]<=2;
		}
		printf("%lld\n",z);
	}
}