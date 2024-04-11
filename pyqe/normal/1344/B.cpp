#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,mn[2][1069],mx[2][1069],fq[2][1069],inf=1e18;
bitset<1069> a[1069];
queue<pair<long long,long long>> q;

int main()
{
	long long i,j,ii,c[2]={0,0},y,x,yy,xx,im,vy[4]={-1,0,1,0},vx[4]={0,1,0,-1},z=0;
	string s;
	
	scanf("%lld%lld",&n,&m);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			mn[ii][i]=inf;
			mx[ii][i]=-inf;
			fq[ii][i]=0;
		}
		swap(n,m);
	}
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]=='#';
			if(a[i][j])
			{
				for(ii=0;ii<2;ii++)
				{
					mn[ii][i]=min(mn[ii][i],j);
					mx[ii][i]=max(mx[ii][i],j);
					fq[ii][i]++;
					swap(i,j);
				}
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			if(fq[ii][i])
			{
				if(mx[ii][i]-mn[ii][i]+1!=fq[ii][i])
				{
					printf("-1\n");
					return 0;
				}
			}
			else
			{
				c[ii]++;
			}
		}
		swap(n,m);
	}
	if(!!c[0]^!!c[1])
	{
		printf("-1\n");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j])
			{
				q.push({i,j});
				a[i][j]=0;
				for(;!q.empty();)
				{
					y=q.front().fr;
					x=q.front().sc;
					q.pop();
					for(im=0;im<4;im++)
					{
						yy=y+vy[im];
						xx=x+vx[im];
						if(yy&&xx&&yy<=n&&xx<=m&&a[yy][xx])
						{
							q.push({yy,xx});
							a[yy][xx]=0;
						}
					}
				}
				z++;
			}
		}
	}
	printf("%lld\n",z);
}