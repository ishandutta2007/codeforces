#include <bits/stdc++.h>

using namespace std;

long long n,dh[100069];
bitset<100069> fq;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	fq[0]=1;
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		dh[i]=dh[k]+1;
		fq[dh[i]]=!fq[dh[i]];
	}
	for(i=0;i<n;i++)
	{
		z+=fq[i];
	}
	printf("%lld\n",z);
}