#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

int main()
{
	long long i,z;
	
	scanf("%lld",&n);
	for(i=1;i<=n*2;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n*2+1);
	z=(a[n]-a[1])*(a[n*2]-a[n+1]);
	for(i=n+1;i<=n*2-1;i++)
	{
		z=min(z,(a[i]-a[i-n+1])*(a[n*2]-a[1]));
	}
	printf("%lld\n",z);
}