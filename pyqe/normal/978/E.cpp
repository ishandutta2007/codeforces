#include <bits/stdc++.h>

using namespace std;

long long n,d;

int main()
{
	long long i,k,sm=0,mn=0,mx=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sm+=k;
		mn=min(mn,sm);
		mx=max(mx,sm);
	}
	printf("%lld\n",max(d+1-mx+mn,0ll));
}