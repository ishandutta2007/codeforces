#include <bits/stdc++.h>

using namespace std;

long long n,a[3];

int main()
{
	long long i,z=0;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",a+i);
	}
	scanf("%lld",&n);
	sort(a,a+3);
	for(i=0;i<2;i++)
	{
		z+=max(n-a[i+1]+a[i],0ll);
	}
	printf("%lld\n",z);
}