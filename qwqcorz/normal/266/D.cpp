#include<bits/stdc++.h>
using namespace std;
const int N=505;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int e[N][N],dis[N][N],p[N][N];

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	double ans=1e18;
	memset(e,-1,sizeof(e));
	memset(dis,0x3f,sizeof(dis));
	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[u][v]=e[v][u]=dis[u][v]=dis[v][u]=w;
	}
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) p[i][j]=j;
	for (int i=1;i<=n;i++) sort(p[i]+1,p[i]+1+n,[&](int x,int y){return dis[i][x]<dis[i][y];});
	for (int i=1;i<=n;i++) ans=min(ans,1.0*dis[i][p[i][n]]);
	for (int u=1;u<=n;u++)
	for (int v=1;v<=n;v++)
	if (~e[u][v])
	{
		int k=p[u][n];
		for (int i=n-1;i>=1;i--)
		if (dis[v][k]<dis[v][p[u][i]])
		{
			int now=p[u][i];
			ans=min(ans,(dis[u][now]+dis[v][k]+e[u][v])/2.0);
			k=now;
		}
	}
	printf("%.10lf",ans);
	
	return 0;
}