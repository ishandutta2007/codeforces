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
int e[N][N],dis[N][N],f[N][N],a[N];

signed main()
{
	memset(e,-1,sizeof(e));
	memset(dis,0x3f,sizeof(dis));
	int n=read(),m=read();
	for (int i=1;i<=n;i++) dis[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		e[u][v]=e[v][u]=dis[u][v]=dis[v][u]=w;
	}
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];
	for (int s=1;s<=n;s++)
	for (int i=1;i<=n;i++)
	{
		int tot=0;
		for (int j=1;j<=n;j++) if (~e[i][j]&&dis[s][j]+e[i][j]==dis[s][i]) tot++;
		for (int t=1;t<=n;t++) if (dis[s][i]+dis[i][t]==dis[s][t]) f[s][t]+=tot;
	}
	for (int i=1;i<=n;i++)
	for (int j=i+1;j<=n;j++) print(f[i][j],' ');
	
	return 0;
}