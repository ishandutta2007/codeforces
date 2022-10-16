#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,d;
pair<long long,pair<long long,long long>> as[4000069];
bitset<2069> sq[2069];

int main()
{
	long long i,j,k,y,x,mn=-inf,mx=inf,mn2=-inf,mx2=inf;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&k);
			as[(i-1)*n+j]={k,{i,j}};
		}
	}
	sort(as+1,as+n*n+1,greater<pair<long long,pair<long long,long long>>>());
	for(i=1;i<=n*n;i++)
	{
		y=as[i].sc.fr;
		x=as[i].sc.sc;
		if(y-x>=mn&&y-x<=mx&&y+x>=mn2&&y+x<=mx2)
		{
			sq[y][x]=1;
			mn=max(mn,y-x-d);
			mx=min(mx,y-x+d);
			mn2=max(mn2,y+x-d);
			mx2=min(mx2,y+x+d);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c","GM"[sq[i][j]]);
		}
		printf("\n");
	}
}