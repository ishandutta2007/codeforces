#include <bits/stdc++.h>
 
using namespace std;
 
#define mp make_pair
#define fr first
#define sc second
 
int n,m,d,a[1001][1001],nr[41][1001][1001],am[41][41],inf=1e9;
vector<pair<int,int>> vl[41];
queue<pair<int,int>> q;
 
int main()
{
	int t,rr,i,j,r,w,sz,y,x,y2,x2,im,yy,xx,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},z;
 
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			vl[a[i][j]].push_back({i,j});
		}
	}
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(r=1;r<=m;r++)
			{
				nr[i][j][r]=inf;
			}
		}
		for(j=1;j<=d;j++)
		{
			am[i][j]=inf;
		}
		sz=vl[i].size();
		for(j=0;j<sz;j++)
		{
			y=vl[i][j].fr;
			x=vl[i][j].sc;
			q.push({y,x});
			nr[i][y][x]=0;
		}
		for(;!q.empty();)
		{
			y=q.front().fr;
			x=q.front().sc;
			w=nr[i][y][x];
			q.pop();
			am[i][a[y][x]]=min(am[i][a[y][x]],w+1+(a[y][x]!=i));
			for(im=0;im<4;im++)
			{
				yy=y+vy[im];
				xx=x+vx[im];
				if(yy&&xx&&yy<=n&&xx<=m&&w+1<nr[i][yy][xx])
				{
					q.push({yy,xx});
					nr[i][yy][xx]=w+1;
				}
			}
		}
	}
	for(i=1;i<=d;i++)
	{
		for(j=1;j<=d;j++)
		{
			for(r=1;r<=d;r++)
			{
				am[j][r]=min(am[j][r],am[j][i]+am[i][r]-1);
			}
		}
	}
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d%d%d",&y,&x,&y2,&x2);
		z=abs(y2-y)+abs(x2-x);
		for(i=1;i<=d;i++)
		{
			for(j=1;j<=d;j++)
			{
				z=min(z,nr[i][y][x]+am[i][j]+nr[j][y2][x2]);
			}
		}
		printf("%d\n",z);
	}
}