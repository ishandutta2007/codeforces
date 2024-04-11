#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],sq[200069],zs=0,inf=1e18;

int main()
{
	long long i,j,ii,k,sm=0,mx[2]={-inf,-inf};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sm+=a[i];
		for(ii=0;ii<2;ii++)
		{
			if(a[i]>mx[ii])
			{
				for(j=1;j>ii;j--)
				{
					mx[j]=mx[j-1];
				}
				mx[ii]=a[i];
				break;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		k=mx[a[i]==mx[0]];
		if(sm-a[i]==k*2)
		{
			zs++;
			sq[zs]=i;
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==zs]);
	}
}