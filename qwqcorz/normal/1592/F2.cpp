#include<bits/stdc++.h>
using namespace std;
const int N=505;

int get()
{
	char c=getchar();
	while (c!='W'&&c!='B') c=getchar();
	return c=='B';
}
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
int a[N][N],e[N][N],x[N],y[N],vis[N],n,m;
bool dfs(int now)
{
	if (vis[now]) return 0;
	vis[now]=1;
	for (int i=1;i<=m;i++)
	if (e[now][i])
	if (!y[i]||dfs(y[i]))
	{
		x[now]=i;
		y[i]=now;
		return 1;
	}
	return 0;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read(),m=read();
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		int x=get();
		if (x) a[i][j]^=1,a[i-1][j]^=1,a[i][j-1]^=1,a[i-1][j-1]^=1;
	}
	int ans=0;
	for (int i=1;i<n;i++)
	for (int j=1;j<m;j++)
	e[i][j]=a[i][j]&&a[n][j]&&a[i][m];
	for (int i=1;i<n;i++) memset(vis,0,sizeof(vis)),ans+=dfs(i)*2;
	for (int i=1;i<n;i++)
	if (x[i])
	{
		int j=x[i];
		a[i][j]^=1;
		a[n][j]^=1;
		a[i][m]^=1;
		a[n][m]^=1;
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) ans+=a[i][j];
	print(ans);
	
	return 0;
}