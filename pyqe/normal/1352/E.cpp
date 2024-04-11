#include <bits/stdc++.h>

using namespace std;

int n,a[8069],ps[8069];
bitset<64000069> vtd;

int main()
{
	int t,rr,i,j,z;
	
	scanf("%d",&t);
	for(rr=1;rr<=t;rr++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",a+i);
			ps[i]=ps[i-1]+a[i];
		}
		for(i=0;i<=n*n;i++)
		{
			vtd[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=i-2;j++)
			{
				vtd[ps[i]-ps[j]]=1;
			}
		}
		z=0;
		for(i=1;i<=n;i++)
		{
			z+=vtd[a[i]];
		}
		printf("%d\n",z);
	}
}