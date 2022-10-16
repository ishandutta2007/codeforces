#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,a[2069][2069],nr[2069][2069],vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},inf=1e18;
queue<pair<long long,long long>> q;

int main()
{
	long long i,j,im,y,x,yy,xx,z=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]-'a';
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
				if(!yy||!xx||yy>n||xx>m||a[yy][xx]!=a[i][j])
				{
					im=-1;
					break;
				}
			}
			if(im==-1)
			{
				q.push({i,j});
				nr[i][j]=1;
			}
		}
	}
	for(;!q.empty();)
	{
		y=q.front().fr;
		x=q.front().sc;
		q.pop();
		z+=nr[y][x];
		for(im=0;im<4;im++)
		{
			yy=y+vy[im];
			xx=x+vx[im];
			if(yy&&xx&&yy<=n&&xx<=m&&a[yy][xx]==a[y][x]&&nr[y][x]+1<nr[yy][xx])
			{
				q.push({yy,xx});
				nr[yy][xx]=nr[y][x]+1;
			}
		}
	}
	printf("%lld\n",z);
}