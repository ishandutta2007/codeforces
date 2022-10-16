#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[200069],pr[200069],ls[200069],lss[200069],sq[200069];

int main()
{
	long long i,j,p,mn,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",pr+i);
	}
	for(i=1;i<=n;i++)
	{
		if(!ls[i])
		{
			nn=0;
			for(p=i;!ls[p];p=pr[p])
			{
				nn++;
				sq[nn]=p;
				ls[p]=nn;
				lss[p]=i;
			}
			if(lss[p]==i)
			{
				mn=1e18;
				for(j=ls[p];j<=nn;j++)
				{
					mn=min(mn,a[sq[j]]);
				}
				z+=mn;
			}
		}
	}
	printf("%lld\n",z);
}