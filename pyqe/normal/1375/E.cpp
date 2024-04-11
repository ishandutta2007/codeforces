#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn,a[1069],zs=0;
pair<long long,long long> aa[1069],sq[1000069];

int main()
{
	long long i,j;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=n;i;i--)
	{
		nn=0;
		for(j=1;j<i;j++)
		{
			if(a[j]>a[i])
			{
				nn++;
				aa[nn]={a[j],j};
			}
		}
		sort(aa+1,aa+nn+1);
		for(j=1;j<=nn;j++)
		{
			zs++;
			sq[zs]={aa[j].sc,i};
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}