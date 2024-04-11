#include<bits/stdc++.h>
using namespace std;
const int N=2e2+5;

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
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
bool vis[N];
int f[N][N],c[N],n,m,inf,ans=0;
bool check(int now)
{
	if (vis[now]) return 1;
	vis[now]=1;
	for (int i=1;i<=n;i++)
	if (i!=now&&f[now][i]<inf)
	{
		if (c[i]>=0&&c[i]!=(c[now]^1)) return 0;
		c[i]=c[now]^1;
		if (!check(i)) return 0;
	}
	return 1;
}

signed main()
{
	memset(vis,0,sizeof(vis));
	memset(c,-1,sizeof(c));
	memset(f,0x3f,sizeof(f));
	inf=f[0][0];
	n=read();
	m=read();
	for (int i=1;i<=n;i++) f[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		if (w==0) f[v][u]=f[u][v]=1;
		else
		{
			f[u][v]=1;
			f[v][u]=-1;
		}
	}
	c[1]=0;
	if (!check(1)) return puts("NO"),0;
	for (int k=1;k<=n;k++)
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for (int i=1;i<=n;i++) if (f[i][i]<0) return puts("NO"),0;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++) ans=max(ans,f[i][j]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	if (ans==f[i][j])
	{
		puts("YES");
		print(ans);
		for (int k=1;k<=n;k++) print(f[i][k],' '); 
		return 0;
	}

	return 0;
}