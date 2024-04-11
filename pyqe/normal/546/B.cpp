#include <bits/stdc++.h>

using namespace std;

long long n,fq[200069];

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=1;i<=n*2;i++)
	{
		k=max(fq[i]-1,0ll);
		fq[i]-=k;
		fq[i+1]+=k;
		z+=k;
	}
	printf("%lld\n",z);
}