#include <bits/stdc++.h>

using namespace std;

long long n,fq[2];

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k%2]++;
	}
	printf("%lld\n",min(fq[0],fq[1]));
}