#include <bits/stdc++.h>

using namespace std;

long long n,fq[200069];

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			fq[i]=0;
		}
		z=-1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			fq[k]++;
			if(fq[k]>=3)
			{
				z=k;
			}
		}
		printf("%lld\n",z);
	}
}