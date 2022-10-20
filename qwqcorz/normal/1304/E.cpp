#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int inf=1e9+7;

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
	int to,next;
}e[2*N];
int head[N],cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
int dep[N],fa[N][21];
void dfs(int now,int father,int deep)
{
	dep[now]=deep;
	fa[now][0]=father;
	for (int i=head[now];i;i=e[i].next)
	if (e[i].to!=father)
	dfs(e[i].to,now,deep+1);
}
int lca(int u,int v)
{
	int now=20;
	if (dep[u]<dep[v]) swap(u,v);
	while (dep[u]!=dep[v])
	{
		if (dep[fa[u][now]]>=dep[v]) u=fa[u][now];
		now--;
	}
	if (u==v) return u;
	for (now=20;now>=0;now--)
	if (fa[u][now]!=fa[v][now])
	{
		u=fa[u][now];
		v=fa[v][now];
	}
	return fa[u][0];
}
int dis(int x,int y)
{
	int l=lca(x,y);
	return dep[x]+dep[y]-2*dep[l];
}

int main()
{
	memset(head,0,sizeof(head));
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0,0);
	for (int j=1;j<=20;j++)
	for (int i=1;i<=n;i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	int m=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read(),a=read(),b=read(),k=read();
		int mn=inf;
		int len1=dis(a,b),len2=dis(a,x)+dis(b,y)+1,len3=dis(a,y)+dis(b,x)+1;
		if (len1%2==k%2) mn=min(mn,len1);
		if (len2%2==k%2) mn=min(mn,len2);
		if (len3%2==k%2) mn=min(mn,len3);
		if (mn<=k) puts("YES");
			  else puts("NO");
	}

	return 0;
}