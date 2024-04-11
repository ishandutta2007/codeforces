#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},inf=1e18;
long long n,m,d,a[2069][2069],nr[2069][2069];
queue<pair<long long,long long>> q;

int main()
{
	long long i,j,ii,im,y,x,yy,xx,mn,z=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				nr[i][j]=inf;
			}
		}
		mn=inf;
		y=1+(n-1)*ii;
		x=1+(m-1)*ii;
		q.push({y,x});
		nr[y][x]=0;
		for(;!q.empty();)
		{
			y=q.front().fr;
			x=q.front().sc;
			q.pop();
			if(a[y][x])
			{
				mn=min(mn,nr[y][x]*d+a[y][x]);
			}
			for(im=0;im<4;im++)
			{
				yy=y+vy[im];
				xx=x+vx[im];
				if(yy&&xx&&yy<=n&&xx<=m&&a[yy][xx]+1&&nr[y][x]+1<nr[yy][xx])
				{
					q.push({yy,xx});
					nr[yy][xx]=nr[y][x]+1;
				}
			}
		}
		z=min(z+mn,inf);
	}
	if(nr[1][1]<inf)
	{
		z=min(z,nr[1][1]*d);
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}