#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+5;
const int p=998244353;

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
struct edge
{
	int to,nxt;
}e[N*2];
int head[N],cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int f[N][3],g[3];
void dfs(int now,int fa)
{
	f[now][0]=1;
	f[now][1]=f[now][2]=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==fa) continue;
		dfs(to,now);
		for (int i=0;i<3;i++) g[i]=f[now][i];
		f[now][0]=g[0]*(f[to][0]+f[to][2])%p;
		f[now][1]=(g[1]*(f[to][0]+2ll*f[to][2])+g[0]*f[to][2])%p;
		f[now][2]=((g[0]+g[1])*(f[to][0]+f[to][1])+g[2]*(2ll*f[to][2]+f[to][0]))%p;
	}
}

signed main()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
//	for (int i=1;i<=n;i++)
//	{
//		print(f[i][0],' ');
//		print(f[i][1],' ');
//		print(f[i][2]);
//	}
	print((f[1][0]+f[1][2])%p);

	return 0;
}