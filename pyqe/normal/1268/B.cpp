#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i,z=0,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		z+=k/2;
		fq[i%2]+=k%2;
	}
	printf("%lld\n",z+min(fq[0],fq[1]));
}