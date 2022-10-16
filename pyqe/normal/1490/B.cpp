#include <bits/stdc++.h>

using namespace std;

long long n,fq[3];

int main()
{
	long long t,rr,i,k,w,z;
	
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
		z=0;
		for(i=0;i<6;i++)
		{
			w=max(fq[i%3]-n/3,0ll);
			z+=w;
			fq[i%3]-=w;
			fq[(i+1)%3]+=w;
		}
		printf("%lld\n",z);
	}
}