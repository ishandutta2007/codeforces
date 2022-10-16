#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[2][100069];

int main()
{
	long long i,k,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		fq[0][abs(d-i)]++;
		fq[1][abs(d-i)]+=k;
	}
	for(i=0;i<n;i++)
	{
		z+=fq[1][i]*(fq[1][i]==fq[0][i]);
	}
	printf("%lld\n",z);
}