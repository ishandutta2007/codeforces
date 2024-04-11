#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[100069];

int main()
{
	long long i,j,z=0;
	
	scanf("%lld",&n);
	nn=(1ll<<n+1)-1;
	for(i=2;i<=nn;i++)
	{
		scanf("%lld",a+i);
		a[i]+=a[i/2];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1ll<<n;j<=nn;j+=1ll<<i)
		{
			z+=abs(a[j]-a[j+(1ll<<i-1)]);
			a[j]=max(a[j],a[j+(1ll<<i-1)]);
		}
	}
	printf("%lld\n",z);
}