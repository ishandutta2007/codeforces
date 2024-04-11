#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1,greater<long long>());
	for(i=1;i<=n;i++)
	{
		z+=a[i]!=a[i+1];
	}
	printf("%lld\n",z);
}