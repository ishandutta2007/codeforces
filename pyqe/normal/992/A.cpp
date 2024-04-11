#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<200069> vtd;

int main()
{
	long long i,k,c=0;
	
	scanf("%lld",&n);
	vtd[100000]=1;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		c+=!vtd[k+100000];
		vtd[k+100000]=1;
	}
	printf("%lld\n",c);
}