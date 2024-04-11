#include <bits/stdc++.h>

using namespace std;

long long n,a[300069],dv=1e9+7;

int main()
{
	long long i,sm=0,p2=1,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
	{
		z=(z+a[i]*(p2+dv-1)+dv-sm)%dv;
		sm=(sm*2+a[i])%dv;
		p2=p2*2%dv;
	}
	printf("%lld\n",z);
}