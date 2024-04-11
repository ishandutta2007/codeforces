#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long as[2][3],zs=0;
pair<long long,long long> a[3];
pair<pair<long long,long long>,pair<long long,long long>> sq[100069];

int main()
{
	long long i,ii,x,y;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld%lld",&x,&y);
		a[i]={x,y};
		for(ii=0;ii<2;ii++)
		{
			as[ii][i]=x;
			swap(x,y);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		sort(as[ii],as[ii]+3);
	}
	for(i=0;i<3;i++)
	{
		x=a[i].fr;
		y=a[i].sc;
		if(x!=as[0][1])
		{
			zs++;
			sq[zs]={{x,y},{as[0][1],y}};
		}
		if(y!=as[1][1])
		{
			zs++;
			sq[zs]={{as[0][1],y},{as[0][1],as[1][1]}};
		}
	}
	printf("%lld\n",zs);
	for(i=1;i<=zs;i++)
	{
		printf("%lld %lld %lld %lld\n",sq[i].fr.fr,sq[i].fr.sc,sq[i].sc.fr,sq[i].sc.sc);
	}
}