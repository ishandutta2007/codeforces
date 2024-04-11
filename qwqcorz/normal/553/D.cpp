#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
bool vis[N];
int a[N],siz[N],q[N],b[N];
bool check(int n,int k,double x)
{
	memset(vis,0,sizeof(vis));
	int h=1,t=0;
	for (int i=1;i<=n;i++) b[i]=floor(siz[i]-siz[i]*x);
	for (int i=1;i<=k;i++) vis[q[++t]=a[i]]=1;
	while (h<=t)
	{
		int now=q[h++];
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (!vis[to]&&--b[to]<0) vis[q[++t]=to]=1;
		}
	}
	return t<n;
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read(),k=read();
	for (int i=1;i<=k;i++) a[i]=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
		siz[u]++,siz[v]++;
	}
	double l=0,r=1;
	for (int T=60;T--;)
	{
		double mid=(l+r)/2;
		if (check(n,k,mid)) l=mid;
					   else r=mid;
	}
	assert(check(n,k,l));
	int ans=0;
	for (int i=1;i<=n;i++) ans+=!vis[i];
	print(ans);
	for (int i=1;i<=n;i++) if (!vis[i]) print(i,' ');
	
	return 0;
}