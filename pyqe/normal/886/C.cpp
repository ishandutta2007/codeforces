#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<200069> vtd;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		z+=!vtd[k];
		vtd[k]=0;
		vtd[i]=1;
	}
	printf("%lld\n",z);
}