#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,z=0;
	bool bad=0,ng=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z+=abs(abs(k)-1);
		if(k==0)
		{
			bad=1;
		}
		if(k<0)
		{
			ng^=1;
		}
	}
	if(!bad&&ng)
	{
		z+=2;
	}
	printf("%lld\n",z);
}