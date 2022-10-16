#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,mx,z=0;
	
	scanf("%lld%lld",&n,&mx);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		for(;mx*2<a[i];mx*=2,z++);
		mx=max(mx,a[i]);
	}
	printf("%lld\n",z);
}