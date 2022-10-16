#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,ys,xs,d[2],nr[2069][2069],vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},inf=1e18;
bitset<2069> a[2069];
deque<pair<long long,long long>> dq;

int main()
{
	long long i,j,ii,im,k,y,x,yy,xx,c[2],z=0;
	char ch;
	
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&ys,&xs,d,d+1);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch=='*';
			nr[i][j]=inf;
		}
	}
	dq.push_back({ys,xs});
	nr[ys][xs]=0;
	for(;!dq.empty();)
	{
		y=dq.front().fr;
		x=dq.front().sc;
		dq.pop_front();
		for(im=0;im<4;im++)
		{
			yy=y+vy[im];
			xx=x+vx[im];
			if(yy&&xx&&yy<=n&&xx<=m&&!a[yy][xx]&&nr[y][x]+im%2<nr[yy][xx])
			{
				if(im%2)
				{
					dq.push_back({yy,xx});
				}
				else
				{
					dq.push_front({yy,xx});
				}
				nr[yy][xx]=nr[y][x]+im%2;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			c[0]=max(xs-j,0ll);
			c[1]=max(j-xs,0ll);
			k=(nr[i][j]-c[0]-c[1])/2;
			for(ii=0;ii<2;ii++)
			{
				c[ii]+=k;
			}
			z+=c[0]<=d[0]&&c[1]<=d[1];
		}
	}
	printf("%lld\n",z);
}