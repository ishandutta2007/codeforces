#include <bits/stdc++.h>

using namespace std;

long long n,d[2];

int main()
{
	long long i,ii,k,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&k);
			d[ii]+=k;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		z+=min(d[ii],n-d[ii]);
	}
	printf("%lld\n",z);
}