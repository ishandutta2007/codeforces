#include <bits/stdc++.h>

using namespace std;

long long n,d=25,mx=0;

int main()
{
	long long i,k;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		mx=max(mx,k);
	}
	printf("%lld\n",max(mx-d,0ll));
}