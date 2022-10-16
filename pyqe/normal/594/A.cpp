#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],inf=1e18;

int main()
{
	long long i,z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n/2;i++)
	{
		z=min(z,a[i+n/2]-a[i]);
	}
	printf("%lld\n",z);
}