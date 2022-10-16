#include <bits/stdc++.h>

using namespace std;

int n,m,dp[1069][1069],sp[10][10][1069][1069],lg2[1069];

int qr(int y,int x,int y2,int x2)
{
	int ly=y2-y+1,lx=x2-x+1,ii,jj,ei,ej,mx=-1e9;
	
	for(ii=0;ii<2;ii++)
	{
		for(jj=0;jj<2;jj++)
		{
			if(!ii)
			{
				ei=y;
			}
			else
			{
				ei=y2-(1<<lg2[ly])+1;
			}
			if(!jj)
			{
				ej=x;
			}
			else
			{
				ej=x2-(1<<lg2[lx])+1;
			}
			mx=max(mx,sp[lg2[ly]][lg2[lx]][ei][ej]);
		}
	}
	return mx;
}

int main()
{
	int t,rr,i,j,ii,jj,k,y,x,y2,x2,lh,rh,md,zz;
	
	for(i=1;i<=1000;i++)
	{
		for(k=i;k>1;k/=2,lg2[i]++);
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%d",&k);
			if(k)
			{
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
			}
		}
	}
	for(ii=0;ii<10;ii++)
	{
		for(jj=0;jj<10;jj++)
		{
			for(i=1;i<=n-(1<<ii)+1;i++)
			{
				for(j=1;j<=m-(1<<jj)+1;j++)
				{
					if(!jj)
					{
						if(!ii)
						{
							sp[ii][jj][i][j]=dp[i][j];
						}
						else
						{
							sp[ii][jj][i][j]=max(sp[ii-1][jj][i][j],sp[ii-1][jj][i+(1<<ii-1)][j]);
						}
					}
					else
					{
						sp[ii][jj][i][j]=max(sp[ii][jj-1][i][j],sp[ii][jj-1][i][j+(1<<jj-1)]);
					}
				}
			}
		}
	}
	scanf("%d",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d%d%d",&y,&x,&y2,&x2);
		zz=0;
		for(lh=1,rh=min(y2-y+1,x2-x+1);lh<=rh;)
		{
			md=(lh+rh)/2;
			k=qr(y+md-1,x+md-1,y2,x2);
			if(k>=md)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		printf("%d\n",zz);
	}
}