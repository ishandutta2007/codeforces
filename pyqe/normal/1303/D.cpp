#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[69];

int main()
{
	long long t,rr,i,k,c,mn,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&d,&n);
		for(i=0;i<69;i++)
		{
			fq[i]=0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			for(c=0;k>1;k/=2,c++);
			fq[c]++;
		}
		mn=1e18;
		z=0;
		for(i=0;i<64;i++)
		{
			k=d>>i&1;
			if(fq[i]&&mn<=64)
			{
				z+=i-mn;
				mn=1e18;
				fq[i]--;
			}
			if(k)
			{
				mn=min(mn,i);
			}
			if(fq[i]&&mn<=64)
			{
				z+=i-mn;
				mn=1e18;
				fq[i]--;
			}
			fq[i+1]+=fq[i]/2;
			fq[i]%=2;
		}
		if(mn<=64)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}