#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=2e6+5;

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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct node
{
	int to,nxt;
}e[M*2];
int head[N],cnte=0;
void add(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int siz[N],fa[N],no[N],cnt=0;
bool vis[N],is[N];
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
inline void merge(int x,int y)
{
	fa[find(x)]=find(y);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
//	freopen("susie.in","r",stdin);
//	freopen("susie.out","w",stdout);

	int n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
		siz[u]++;
		siz[v]++;
	}
	int Min=n,id=0;
	for (int i=1;i<=n;i++) if (Min>siz[i]) Min=siz[i],id=i;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=head[id];i;i=e[i].nxt) vis[e[i].to]=1;
	for (int i=1;i<=n;i++) if (!vis[i]) fa[i]=id,is[i]=1;
	for (int i=1;i<=n;i++) if (!is[i]) no[++cnt]=i;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n;i++)
	{
		int tot=0;
		for (int j=head[i];j;j=e[j].nxt)
		{
			int to=e[j].to;
			vis[to]=1;
			tot+=is[to];
		}
		if (tot+cnt<n) merge(i,id);
		for (int j=1;j<=cnt;j++) if (!vis[no[j]]) merge(i,no[j]);
		for (int j=head[i];j;j=e[j].nxt) vis[e[j].to]=0;
	}
	int ans=-1;
	for (int i=1;i<=n;i++) ans+=i==fa[i];
	print(ans);

	return 0;
}