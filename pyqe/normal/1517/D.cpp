#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18,vy[4]={0,1,0,-1},vx[4]={1,0,-1,0};
long long n,m,d,a[2][569][569],dp[2][569][569];

int main()
{
	long long i,j,r,ii,im,yy,xx,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n-ii;i++)
		{
			for(j=1;j<=m-!ii;j++)
			{
				scanf("%lld",&a[ii][i][j]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			dp[0][i][j]=0;
		}
	}
	for(i=0;i<d/2;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(r=1;r<=m;r++)
			{
				dp[1][j][r]=inf;
				for(im=0;im<4;im++)
				{
					yy=j+vy[im];
					xx=r+vx[im];
					if(yy&&xx&&yy<=n&&xx<=m)
					{
						dp[1][j][r]=min(dp[1][j][r],dp[0][yy][xx]+a[im%2][min(j,yy)][min(r,xx)]);
					}
				}
			}
		}
		for(j=1;j<=n;j++)
		{
			for(r=1;r<=m;r++)
			{
				dp[0][j][r]=dp[1][j][r];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(d%2==0)
			{
				z=dp[0][i][j]*2;
			}
			else
			{
				z=-1;
			}
			printf("%lld%c",z," \n"[j==m]);
		}
	}
}