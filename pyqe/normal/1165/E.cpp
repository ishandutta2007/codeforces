#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],aa[200069],dv=998244353;

int main()
{
	long long i,k,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k*i*(n+1-i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",aa+i);
	}
	sort(aa+1,aa+n+1,greater<long long>());
	for(i=1;i<=n;i++)
	{
		z=(z+a[i]%dv*aa[i])%dv;
	}
	printf("%lld\n",z);
}