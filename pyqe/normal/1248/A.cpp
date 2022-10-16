#include <bits/stdc++.h>

using namespace std;

long long n,fq[2][2];

int main()
{
	long long t,rr,i,ii,iii,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(iii=0;iii<2;iii++)
			{
				fq[ii][iii]=0;
			}
			scanf("%lld",&n);
			for(i=0;i<n;i++)
			{
				scanf("%lld",&k);
				fq[ii][k%2]++;
			}
		}
		z=0;
		for(ii=0;ii<2;ii++)
		{
			z+=fq[0][ii]*fq[1][ii];
		}
		printf("%lld\n",z);
	}
}