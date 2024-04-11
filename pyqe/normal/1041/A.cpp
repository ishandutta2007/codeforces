#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,mn=1e18,mx=0,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		mn=min(mn,k);
		mx=max(mx,k);
	}
	printf("%lld\n",mx-mn+1-n);
}