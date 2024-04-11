#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,a[200069];

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	a[n+1]=inf;
	for(i=n;i;i--)
	{
		a[i]=max(min(a[i],a[i+1]-1),0ll);
		z+=a[i];
	}
	printf("%lld\n",z);
}