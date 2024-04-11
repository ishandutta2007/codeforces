#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,nxt;
}e[N];
int head[N],cnte=0,siz[N];
void add_edge(int u,int v)
{
	siz[v]++;
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int f[N],fa[N],nxt[N],deep[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
int q[N],h=1,t=0;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read();
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++) f[i]=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if (find(u)==find(v)) return puts("0"),0;
		fa[find(v)]=find(u);
		nxt[u]=v;
	}
	for (int i=1;i<=n;i++) if (i==fa[i])
	for (int j=i;j;j=nxt[j]) deep[nxt[j]]=deep[j]+1;
	for (int i=1;i<=n;i++)
	if (f[i])
	{
		if (find(i)!=find(f[i])) add_edge(find(f[i]),find(i));
		else if (deep[f[i]]>=deep[i]) return puts("0"),0;
	}
	for (int i=1;i<=n;i++) if (!siz[i]&&fa[i]==i) q[++t]=i;
	while (h<=t)
	{
		int now=q[h++];
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (!--siz[to]) q[++t]=to;
		}
	}
	for (int i=1;i<=n;i++) if (siz[i]) return puts("0"),0;
	for (int i=1;i<=t;i++)
	for (int j=q[i];j;j=nxt[j])
	print(j,' ');
	
	return 0;
}