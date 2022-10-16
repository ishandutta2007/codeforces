#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n;
pair<long long,long long> a[2][1069];

int main()
{
	long long i,j,ii,y,x,yy,xx,p;
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld",&y,&x);
			a[ii][i]={y,x};
		}
		sort(a[ii]+1,a[ii]+n+1);
	}
	for(i=1;i<=n;i++)
	{
		y=a[0][i].fr+a[1][1].fr;
		x=a[0][i].sc+a[1][1].sc;
		for(j=1;j<=n;j++)
		{
			yy=y-a[0][j].fr;
			xx=x-a[0][j].sc;
			p=lower_bound(a[1]+1,a[1]+n+1,mp(yy,xx))-a[1];
			if(p>n||a[1][p]!=mp(yy,xx))
			{
				break;
			}
		}
		if(j>n)
		{
			printf("%lld %lld\n",y,x);
			break;
		}
	}
}