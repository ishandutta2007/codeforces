#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[3][2],as[2][3],zs=0;
pair<long long,long long> sq[2069];

int main()
{
	long long i,j,ii;
	
	for(i=0;i<3;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[i][ii]);
			as[ii][i]=a[i][ii];
		}
	}
	for(ii=0;ii<2;ii++)
	{
		sort(as[ii],as[ii]+3);
	}
	for(i=as[0][0];i<=as[0][2];i++)
	{
		zs++;
		sq[zs]={i,as[1][1]};
	}
	for(i=0;i<3;i++)
	{
		for(j=min(a[i][1],as[1][1]);j<=max(a[i][1],as[1][1]);j++)
		{
			if(j!=as[1][1])
			{
				zs++;
				sq[zs]={a[i][0],j};
			}
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld\n",sq[i].fr,sq[i].sc);
	}
}