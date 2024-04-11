#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long i,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		z+=a[i]*max(d-i+1,1ll);
	}
	printf("%lld\n",z);
}