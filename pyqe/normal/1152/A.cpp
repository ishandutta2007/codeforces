#include <bits/stdc++.h>

using namespace std;

long long n[2],fq[2][2];

int main()
{
	long long i,ii,k,z=0;
	
	scanf("%lld%lld",n,n+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<n[ii];i++)
		{
			scanf("%lld",&k);
			fq[ii][k%2]++;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		z+=min(fq[ii][0],fq[!ii][1]);
	}
	printf("%lld\n",z);
}