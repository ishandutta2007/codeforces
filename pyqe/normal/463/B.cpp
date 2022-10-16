#include <bits/stdc++.h>

using namespace std;

long long n,k;

int main()
{
	long long i,mx=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		mx=max(mx,k);
	}
	printf("%lld\n",mx);
}