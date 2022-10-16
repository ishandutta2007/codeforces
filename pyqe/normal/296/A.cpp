#include <bits/stdc++.h>

using namespace std;

long long n,fq[100069];

int main()
{
	long long i,k,mx=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
		mx=max(mx,fq[k]);
	}
	if(mx<=(n+1)/2)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}