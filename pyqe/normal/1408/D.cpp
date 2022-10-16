#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,inf=1e18;
pair<long long,long long> a[2][2069],as[4000069];

int main()
{
	long long i,j,ii,y,x,mx=0,z=inf;
	
	scanf("%lld%lld",&n,&m);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&y,&x);
			a[ii][i]={y,x};
		}
		swap(n,m);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			as[(i-1)*m+j]={max(a[1][j].fr-a[0][i].fr+1,0ll),a[1][j].sc-a[0][i].sc+1};
		}
	}
	as[n*m+1]={0,0};
	sort(as+1,as+n*m+2,greater<pair<long long,long long>>());
	for(i=1;i<=n*m+1;i++)
	{
		y=as[i].fr;
		x=as[i].sc;
		z=min(z,y+mx);
		mx=max(mx,x);
	}
	printf("%lld\n",z);
}