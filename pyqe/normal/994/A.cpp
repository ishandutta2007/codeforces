#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],sq[100069],zs=0;
bitset<100069> spc;

int main()
{
	long long i,k;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld",&k);
		spc[k]=1;
	}
	for(i=1;i<=n;i++)
	{
		if(spc[a[i]])
		{
			zs++;
			sq[zs]=a[i];
		}
	}
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}