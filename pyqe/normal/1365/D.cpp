#include <bits/stdc++.h>

using namespace std;

long long n,m,yk[269],a[1069][1069],cc,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1};
string ky=".#GB";

void dfs(long long y,long long x)
{
	long long im,yy,xx;
	
	cc+=a[y][x]==2;
	a[y][x]=1;
	for(im=0;im<4;im++)
	{
		yy=y+vy[im];
		xx=x+vx[im];
		if(yy&&xx&&yy<=n&&xx<=m&&a[yy][xx]!=1)
		{
			dfs(yy,xx);
		}
	}
}

int main()
{
	long long t,rr,i,j,im,yy,xx,c;
	bool bad;
	string s;
	
	for(i=0;i<4;i++)
	{
		yk[ky[i]]=i;
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		c=0;
		for(i=1;i<=n;i++)
		{
			cin>>s;
			for(j=1;j<=m;j++)
			{
				a[i][j]=yk[s[j-1]];
				c+=a[i][j]==2;
			}
		}
		bad=0;
		for(i=1;i<=n&&!bad;i++)
		{
			for(j=1;j<=m&&!bad;j++)
			{
				if(a[i][j]==3)
				{
					for(im=0;im<4;im++)
					{
						yy=i+vy[im];
						xx=j+vx[im];
						if(yy&&xx&&yy<=n&&xx<=m)
						{
							if(a[yy][xx]==2)
							{
								bad=1;
								break;
							}
							a[yy][xx]+=!a[yy][xx];
						}
					}
				}
			}
		}
		cc=0;
		if(!a[n][m])
		{
			dfs(n,m);
		}
		if(!bad&&cc==c)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}