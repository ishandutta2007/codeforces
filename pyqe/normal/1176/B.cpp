#include <bits/stdc++.h>

using namespace std;

long long n,fq[3];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=0;i<3;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k%3]++;
		}
		z=fq[0];
		k=min(fq[1],fq[2]);
		z+=k;
		fq[1]-=k;
		fq[2]-=k;
		z+=fq[1]/3+fq[2]/3;
		printf("%lld\n",z);
	}
}