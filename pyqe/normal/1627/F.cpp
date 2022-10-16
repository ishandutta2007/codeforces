#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long vy[4]={-1,0,1,0},vx[4]={0,-1,0,1},inf=1e18;
long long n,d,ed[569][569][4],nr[569][569];
priority_queue<pair<long long,pair<long long,long long>>> pq;

int main()
{
	long long t,rr,i,j,im,y,x,y2,x2,w,yy,xx,ww;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<=d;i++)
		{
			for(j=0;j<=d;j++)
			{
				for(im=0;im<4;im++)
				{
					ed[i][j][im]=0;
				}
				nr[i][j]=inf;
			}
		}
		for(i=0;i<n;i++)
		{
			scanf("%lld%lld%lld%lld",&y,&x,&y2,&x2);
			if(y==y2)
			{
				if(x>x2)
				{
					swap(x,x2);
				}
				ed[y-1][x][2]++;
				ed[y][x][0]++;
				ed[d-(y-1)][d-x][0]++;
				ed[d-y][d-x][2]++;
			}
			else
			{
				if(y>y2)
				{
					swap(y,y2);
				}
				ed[y][x-1][3]++;
				ed[y][x][1]++;
				ed[d-y][d-(x-1)][1]++;
				ed[d-y][d-x][3]++;
			}
		}
		for(;!pq.empty();pq.pop());
		pq.push({0,{d/2,d/2}});
		nr[d/2][d/2]=0;
		for(;!pq.empty();)
		{
			w=-pq.top().fr;
			y=pq.top().sc.fr;
			x=pq.top().sc.sc;
			pq.pop();
			if(w>nr[y][x])
			{
				continue;
			}
			if(!y||!x||y==d||x==d)
			{
				break;
			}
			for(im=0;im<4;im++)
			{
				yy=y+vy[im];
				xx=x+vx[im];
				ww=w+ed[y][x][im];
				if(ww<nr[yy][xx])
				{
					pq.push({-ww,{yy,xx}});
					nr[yy][xx]=ww;
				}
			}
		}
		printf("%lld\n",n-w);
	}
}