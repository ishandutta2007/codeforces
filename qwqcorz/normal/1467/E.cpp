#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

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
void Answer0()
{
	puts("0");
	exit(0);
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
int a[N],b[N],t[N],tot[N],siz[N],son[N],w[N];
bool is[N];
void add(int now,int father)
{
	t[a[now]]++;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		add(to,now);
	}
}
void clear(int now,int father)
{
	t[a[now]]=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		clear(to,now);
	}
}
void dfs(int now,int father)
{
	siz[now]=1,son[now]=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
		siz[now]+=siz[to];
		if (siz[son[now]]<siz[to]) son[now]=to;
	}
}
void dsu(int now,int father)
{
	int tmp=0;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father||to==son[now]) continue;
		dsu(to,now);
		if (t[a[now]]>0) tmp++,w[now]=to;
		clear(to,now);
	}
	if (son[now])
	{
		dsu(son[now],now);
		if (t[a[now]]>0) tmp++,w[now]=son[now];
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			if (to==father||to==son[now]) continue;
			add(to,now);
		}
	}
	t[a[now]]++;
	if (t[a[now]]!=tot[a[now]]) tmp++;
						   else is[now]=1;
	if (tmp>1) Answer0();
//	print(now,':');for (int i=1;i<=4;i++) print(t[i]," \n"[i==4]);
}
void tcf(int now,int father)
{
	t[now]+=t[father];
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		tcf(to,now);
	}
}

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read();
	for (int i=1;i<=n;i++) b[i]=a[i]=read();
	sort(b+1,b+1+n);
	int cnt=unique(b+1,b+1+n)-b-1;
	for (int i=1;i<=n;i++) tot[a[i]=lower_bound(b+1,b+1+cnt,a[i])-b]++;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	dsu(1,0);
	memset(t,0,sizeof(t));
	for (int i=1;i<=n;i++)
	if (tot[a[i]]>1)
	{
		if (is[i]) t[1]++,t[w[i]]--;
			  else t[i]++;
	}
	tcf(1,0);
	int ans=0;
	for (int i=1;i<=n;i++) ans+=!t[i];
	print(ans);
	
	return 0;
}