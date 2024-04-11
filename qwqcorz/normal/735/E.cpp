#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int K=25;
const int p=1e9+7;

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
struct edge
{
	int to,nxt;
}e[N*2];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int n,k,f[N][2][K];
void dfs(int now,int father)
{
	f[now][0][k]=f[now][1][0]=1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
		memset(f[0],0,sizeof(f[0]));
		for (int x=0;x<=1;x++)
		for (int i=0;i<=k;i++)
		for (int y=0;y<=1;y++)
		for (int j=0;j<=k-y;j++)
		{
			int u=y,v=j;
			if (u==0){if (--v<0) v=0,u=1;}
				 else v++;
			if (i==v?x<u:i>v) u=x,v=i;
			f[0][u][v]=(f[0][u][v]+1LL*f[now][x][i]*f[to][y][j])%p;
		}
		memcpy(f[now],f[0],sizeof(f[now]));
	}
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read(),k=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	int ans=0;
	for (int i=0;i<=k;i++) ans=(ans+f[1][0][i])%p;
	print(ans);
	
	return 0;
}