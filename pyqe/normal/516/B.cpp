#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,fq[2069][2069],sq[2069][2069];
bitset<2069> vtd[2069];
queue<pair<long long,long long>> q;

int main()
{
	long long i,j,y,x,yy,xx,im,jm,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},c=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			vtd[i][j]=s[j-1]=='*';
			c+=vtd[i][j];
			sq[i][j]=vtd[i][j]*4;
		}
	}
	for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=m+1;j++)
		{
			if(!i||!j||i>n||j>m||vtd[i][j])
			{
				for(im=0;im<4;im++)
				{
					yy=i+vy[im];
					xx=j+vx[im];
					if(yy>0&&xx>0&&yy<=n&&xx<=m)
					{
						fq[yy][xx]++;
						if(!vtd[yy][xx]&&fq[yy][xx]==3)
						{
							q.push({yy,xx});
						}
					}
				}
			}
		}
	}
	for(;!q.empty();)
	{
		y=q.front().fr;
		x=q.front().sc;
		q.pop();
		if(vtd[y][x]||fq[y][x]!=3)
		{
			continue;
		}
		for(im=0;im<4;im++)
		{
			yy=y+vy[im];
			xx=x+vx[im];
			if(yy&&xx&&yy<=n&&xx<=m&&!vtd[yy][xx])
			{
				vtd[y][x]=1;
				vtd[yy][xx]=1;
				c+=2;
				sq[y][x]=im;
				sq[yy][xx]=im^2;
				y=yy;
				x=xx;
				for(jm=0;jm<4;jm++)
				{
					yy=y+vy[jm];
					xx=x+vx[jm];
					if(yy&&xx&&yy<=n&&xx<=m)
					{
						fq[yy][xx]++;
						if(!vtd[yy][xx]&&fq[yy][xx]==3)
						{
							q.push({yy,xx});
						}
					}
				}
				break;
			}
		}
	}
	if(c<n*m)
	{
		printf("Not unique\n");
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				printf("%c","v<^>*"[sq[i][j]]);
			}
			printf("\n");
		}
	}
}