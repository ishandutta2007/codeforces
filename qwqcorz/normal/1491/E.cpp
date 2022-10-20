#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
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
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	bool used;
	int to,nxt;
}e[N*2];
int head[N],cnte=1;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
bool is[N];
int siz[N],f[N],sum;
void dfs(int now,int father)
{
	siz[now]=1;
	for (int i=head[now];i;i=e[i].nxt)
	if (!e[i].used)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs(to,now);
		siz[now]+=siz[to];
	}
}
pair<int,int>find(int now,int father)
{
	for (int i=head[now];i;i=e[i].nxt)
	if (!e[i].used)
	{
		int to=e[i].to;
		if (to==father) continue;
		if (is[siz[to]]&&is[sum-siz[to]])
		{
			e[i].used=e[i^1].used=1;
			return mk(now,to);
		}
		pair<int,int>tmp=find(to,now);
		if (tmp.fi>0) return tmp;
	}
	return mk(0,0);
}
bool check(int now)
{
	dfs(now,0);
	sum=siz[now];
	if (sum==1) return 1;
	pair<int,int>myh=find(now,0);
	if (!myh.fi) return 0;
	return check(myh.fi)&&check(myh.se);
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read();
	is[f[1]=f[2]=1]=1;
	for (int i=3;(f[i]=f[i-1]+f[i-2])<=n;i++) is[f[i]]=1;
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	puts(is[n]&&check(1)?"YES":"NO");
	
	return 0;
}