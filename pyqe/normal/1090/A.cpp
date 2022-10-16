#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],dd[200069];

int main()
{
	long long i,j,k,mx=-1e18,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",dd+i);
		a[i]=-1e18;
		for(j=0;j<dd[i];j++)
		{
			scanf("%lld",&k);
			a[i]=max(a[i],k);
		}
		mx=max(mx,a[i]);
	}
	for(i=1;i<=n;i++)
	{
		z+=(mx-a[i])*dd[i];
	}
	printf("%lld\n",z);
}