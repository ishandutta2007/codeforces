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
int x,ans,a[N];
bool is[N];
void dfs(int now,int father)
{
	int tot=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
		tot+=is[to];
		a[now]^=a[to];
		is[now]|=is[to];
	}
	is[now]|=a[now]==x;
	if (!x) ans|=!a[now];
	else ans|=tot>=2||(!a[now]&&is[now]);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int T=read();
	while (T--)
	{
		x=ans=cnte=0;
		int n=read(),k=read();
		for (int i=1;i<=n;i++) head[i]=is[i]=0;
		for (int i=1;i<=n;i++) x^=a[i]=read();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			add_edge(u,v);
			add_edge(v,u);
		}
		if (!(x&&k==2)) dfs(1,0);
		puts(ans?"YES":"NO");
	}
	
	return 0;
}