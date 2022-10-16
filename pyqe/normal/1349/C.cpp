#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,nr[1069][1069],inf=1e18;
bitset<1069> a[1069];
queue<pair<long long,long long>> q;

int main()
{
	long long t,rr,i,j,y,x,w,yy,xx,im,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1};
	string s;
	
	scanf("%lld%lld%lld",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]-'0';
			nr[i][j]=inf;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			for(im=0;im<4;im++)
			{
				yy=i+vy[im];
				xx=j+vx[im];
				if(yy&&xx&&yy<=n&&xx<=m&&a[yy][xx]==a[i][j])
				{
					im=-1;
					break;
				}
			}
			if(im==-1)
			{
				q.push({i,j});
				nr[i][j]=0;
			}
		}
	}
	for(;!q.empty();)
	{
		y=q.front().fr;
		x=q.front().sc;
		q.pop();
		w=nr[y][x];
		for(im=0;im<4;im++)
		{
			yy=y+vy[im];
			xx=x+vx[im];
			if(yy&&xx&&yy<=n&&xx<=m&&w+1<nr[yy][xx])
			{
				q.push({yy,xx});
				nr[yy][xx]=w+1;
			}
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&y,&x,&w);
		w=max(w-nr[y][x],0ll);
		printf("%lld\n",(w+a[y][x])%2);
	}
}