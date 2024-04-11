#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,mx=-1e18,sm=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		mx=max(mx,k);
		sm+=k;
	}
	if(sm%2==0&&mx<=sm-mx)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}