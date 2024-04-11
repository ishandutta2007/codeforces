#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,sq[1069][1069];
string ky="URDLX";
pair<long long,long long> a[1069][1069];
bitset<1069> vtd[1069];
queue<pair<long long,long long>> q;

int main()
{
	long long i,j,y,x,yy,xx,im,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld%lld",&a[i][j].fr,&a[i][j].sc);
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!vtd[i][j]&&(a[i][j]==mp(i,j)||a[i][j]==mp(-1ll,-1ll)))
			{
				q.push({i,j});
				vtd[i][j]=1;
				sq[i][j]=4;
				for(;!q.empty();)
				{
					y=q.front().fr;
					x=q.front().sc;
					q.pop();
					for(im=0;im<4;im++)
					{
						yy=y+vy[im];
						xx=x+vx[im];
						if(yy&&xx&&yy<=n&&xx<=n&&!vtd[yy][xx]&&a[yy][xx]==a[i][j])
						{
							q.push({yy,xx});
							vtd[yy][xx]=1;
							sq[yy][xx]=im^2;
							if(a[i][j]==mp(-1ll,-1ll)&&y==i&&x==j)
							{
								sq[i][j]=im;
							}
						}
					}
				}
				if(a[i][j]==mp(-1ll,-1ll)&&sq[i][j]==4)
				{
					printf("INVALID\n");
					return 0;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(!vtd[i][j])
			{
				printf("INVALID\n");
				return 0;
			}
		}
	}
	printf("VALID\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%c",ky[sq[i][j]]);
		}
		printf("\n");
	}
}