#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		fq[k%2]++;
	}
	k=min(fq[0],fq[1]);
	z+=k;
	fq[0]-=k;
	fq[1]-=k;
	z+=fq[1]/3;
	printf("%lld\n",z);
}