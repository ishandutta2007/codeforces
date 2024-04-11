#include <bits/stdc++.h>

using namespace std;

long long n,d,fq[100069];

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=min(d,n);i++)
	{
		fq[i*i%d]+=(n-i)/d+1;
	}
	for(i=0;i<d;i++)
	{
		z+=fq[i]*fq[(d-i)%d];
	}
	printf("%lld\n",z);
}