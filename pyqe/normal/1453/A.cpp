#include <bits/stdc++.h>

using namespace std;

long long n[2],ls[169];

int main()
{
	long long t,rr,i,ii,k,z;
	
	scanf("%lld",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%lld%lld",n,n+1);
		z=0;
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<n[ii];i++)
			{
				scanf("%lld",&k);
				z+=ls[k]==rr;
				ls[k]=rr;
			}
		}
		printf("%lld\n",z);
	}
}