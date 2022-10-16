#include <bits/stdc++.h>

using namespace std;

long long n,z=0;
vector<long long> sq;

int main()
{
	long long i,k,l=-1;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k==l+1)
		{
			sq[z-1]=k;
		}
		else
		{
			sq.push_back(1);
			z++;
		}
		l=k;
	}
	printf("%lld\n",z);
	for(i=0;i<z;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==z-1]);
	}
}