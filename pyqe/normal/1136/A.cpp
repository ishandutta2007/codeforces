#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",a+i,a+i);
	}
	scanf("%lld",&d);
	for(i=1;i<=n;i++)
	{
		z+=a[i]>=d;
	}
	printf("%lld\n",z);
}