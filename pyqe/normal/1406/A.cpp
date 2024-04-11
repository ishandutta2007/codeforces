#include <bits/stdc++.h>

using namespace std;

long long n,ma=100,fq[169];

int main()
{
	long long t,rr,i,ii,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<=ma;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
		}
		z=0;
		for(ii=0;ii<2;ii++)
		{
			for(i=0;fq[i]>ii;i++);
			z+=i;
		}
		printf("%lld\n",z);
	}
}