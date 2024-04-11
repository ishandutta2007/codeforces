#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dv=1e4+7;

int main()
{
	long long i,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		z=(z+a[i]*a[n+1-i])%dv;
	}
	printf("%lld\n",z);
}