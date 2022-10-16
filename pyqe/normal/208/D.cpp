#include <bits/stdc++.h>

using namespace std;

long long n,d=0,a[1069],wg[1069],sq[1069];

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=5;i++)
	{
		scanf("%lld",wg+i);
	}
	for(i=1;i<=n;i++)
	{
		d+=a[i];
		for(j=5;j;j--)
		{
			sq[j]+=d/wg[j];
			d%=wg[j];
		}
	}
	for(i=1;i<=5;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==5]);
	}
	printf("%lld\n",d);
}