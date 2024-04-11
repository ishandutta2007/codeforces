#include <bits/stdc++.h>

using namespace std;

int n,m,yk[26],a[501][501],fh[4][501][501],dp[501][501],ps[501][501][501];

int main()
{
	int t,rr,i,j,r,ii,jj,ui,uj,k,w,y,x,y2,x2,lh,rh,md,zz;
	string s;
	
	yk[17]=3;
	yk[6]=2;
	yk[24]=1;
	yk[1]=0;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++)
	{
		cin>>s;
		for(j=1;j<=m;j++)
		{
			a[i][j]=yk[s[j-1]-'A'];
		}
	}
	for(ii=0;ii<4;ii++)
	{
		ui=!(ii/2)*2-1;
		uj=!(ii%2)*2-1;
		for(i=1+(n-1)*(ii/2);i!=(n+1)*!(ii/2);i+=ui)
		{
			for(j=1+(m-1)*(ii%2);j!=(m+1)*!(ii%2);j+=uj)
			{
				fh[ii][i][j]=(min(min(fh[ii][i-ui][j],fh[ii][i][j-uj]),fh[ii][i-ui][j-uj])+1)*(a[i][j]==ii);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			w=0;
			k=fh[0][i][j];
			ii=i-k*2+1;
			jj=j-k*2+1;
			if(ii>0&&jj>0&&ii<=n&&jj<=m)
			{
				w=k*(fh[1][i][jj]==k&&fh[2][ii][j]==k&&fh[3][ii][jj]==k);
			}
			for(r=0;r<=max(n,m);r++)
			{
				ps[r][i][j]=ps[r][i-1][j]+ps[r][i][j-1]-ps[r][i-1][j-1];
			}
			ps[w][i][j]++;
		}
	}
	for(rr=0;rr<t;rr++)
	{
		scanf("%d%d%d%d",&y,&x,&y2,&x2);
		zz=0;
		for(lh=1,rh=min(y2-y+1,x2-x+1)/2;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(ps[md][y2][x2]-ps[md][y+md*2-2][x2]-ps[md][y2][x+md*2-2]+ps[md][y+md*2-2][x+md*2-2])
			{
				zz=md*2;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		printf("%d\n",zz*zz);
	}
}