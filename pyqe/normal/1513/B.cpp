#include <bits/stdc++.h>

using namespace std;

const long long dv=1e9+7;
long long n,a[200069];

int main()
{
	long long t,rr,i,sm,c,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		sm=(1ll<<30)-1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			sm&=a[i];
		}
		c=0;
		for(i=1;i<=n;i++)
		{
			c+=a[i]==sm;
		}
		z=c*(c-1)%dv;
		for(i=1;i<=n-2;i++)
		{
			z=z*i%dv;
		}
		printf("%lld\n",z);
	}
}