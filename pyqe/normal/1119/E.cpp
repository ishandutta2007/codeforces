#include <bits/stdc++.h>

using namespace std;

long long n,fq=0;

int main()
{
	long long i,k,c,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		c=min(k/2,fq);
		z+=c;
		k-=c*2;
		fq-=c;
		z+=k/3;
		k%=3;
		fq+=k;
	}
	printf("%lld\n",z);
}