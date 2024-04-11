#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d;
bitset<1069> a[1069],vtd[1069],spc[1069];
queue<pair<long long,long long>> q;

int main()
{
	long long i,j,y,x,yy,xx,im,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1};
	string s;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	d=n*m-d;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]=='#';
			vtd[i][j]=a[i][j];
			d-=a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!vtd[i][j])
			{
				q.push({i,j});
				vtd[i][j]=1;
				for(;d;d--)
				{
					y=q.front().fr;
					x=q.front().sc;
					q.pop();
					spc[y][x]=1;
					for(im=0;im<4;im++)
					{
						yy=y+vy[im];
						xx=x+vx[im];
						if(yy&&xx&&yy<=n&&xx<=m&&!vtd[yy][xx])
						{
							q.push({yy,xx});
							vtd[yy][xx]=1;
						}
					}
				}
				j=-1;
				break;
			}
		}
		if(j==-1)
		{
			break;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%c","X.#"[a[i][j]*2+spc[i][j]]);
		}
		printf("\n");
	}
}