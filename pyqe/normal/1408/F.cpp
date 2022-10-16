#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,zs=0;
pair<long long,long long> sq[500069];

int main()
{
	long long i,j,ii,k,l;
	
	scanf("%lld",&n);
	for(d=1;d<<1<=n;d<<=1);
	for(ii=0;ii<2;ii++)
	{
		k=1+(n-d)*ii;
		for(i=0;1ll<<i<d;i++)
		{
			for(j=0;j<d;j++)
			{
				if(!(j>>i&1))
				{
					zs++;
					sq[zs]={k+j,k+(j|1ll<<i)};
				}
			}
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		k=sq[i].fr;
		l=sq[i].sc;
		printf("%lld %lld\n",k,l);
	}
}