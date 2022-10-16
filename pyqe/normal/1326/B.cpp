#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long i,k,mx=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		printf("%lld%c",mx+k," \n"[i==n-1]);
		mx=max(mx,mx+k);
	}
}