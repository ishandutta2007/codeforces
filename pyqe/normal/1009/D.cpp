#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,zs=0;
pair<long long,long long> sq[100069];

int main()
{
	long long i,j,k,l;
	
	scanf("%lld%lld",&n,&m);
	if(m<n-1)
	{
		printf("Impossible\n");
		return 0;
	}
	for(i=1;i<n;i++)
	{
		zs++;
		sq[zs]={i,i+1};
	}
	for(i=1;i<=n&&zs<m;i++)
	{
		for(j=i+2;j<=n&&zs<m;j++)
		{
			if(__gcd(i,j)==1)
			{
				zs++;
				sq[zs]={i,j};
			}
		}
	}
	if(zs<m)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("Possible\n");
		for(i=1;i<=zs;i++)
		{
			k=sq[i].fr;
			l=sq[i].sc;
			printf("%lld %lld\n",k,l);
		}
	}
}