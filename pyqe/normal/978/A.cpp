#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],sq[100069],zs=0;
bitset<100069> vtd;

int main()
{
	long long i;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n;i;i--)
	{
		if(!vtd[a[i]])
		{
			zs++;
			sq[zs]=a[i];
			vtd[a[i]]=1;
		}
	}
	printf("%lld\n",zs);
	for(i=zs;i;i--)
	{
		printf("%lld%c",sq[i]," \n"[i==1]);
	}
}