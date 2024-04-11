#include <bits/stdc++.h>

using namespace std;

long long n,mx=0,fq[169];

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
		mx=max(mx,fq[k]);
	}
	printf("%lld\n",mx);
}