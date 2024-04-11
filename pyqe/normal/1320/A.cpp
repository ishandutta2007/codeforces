#include <bits/stdc++.h>

using namespace std;

long long n,sm[600069];

int main()
{
	long long i,k,mx=-1e18;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sm[k+n-i]+=k;
		mx=max(mx,sm[k+n-i]);
	}
	printf("%lld\n",mx);
}