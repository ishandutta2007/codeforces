#include <bits/stdc++.h>

using namespace std;

long long n,ls[200069],fq[200069],inf=1e18;

int main()
{
	long long t,rr,i,k,c,mx,z;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		mx=-inf;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(ls[k]<rr)
			{
				fq[k]=0;
				c++;
				ls[k]=rr;
			}
			fq[k]++;
			mx=max(mx,fq[k]);
		}
		z=max(min(c-1,mx),min(c,mx-1));
		printf("%lld\n",z);
	}
}