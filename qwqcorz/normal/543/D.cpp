#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int p=1e9+7;

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
int power(int a,int b)
{
	int ret=1;
	while (b)
	{
		if (b&1) ret=1LL*ret*a%p;
		a=1LL*a*a%p;
		b/=2;
	}
	return ret;
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
int f[N];
void dfs0(int now,int father)
{
	f[now]=1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs0(to,now);
		f[now]=1LL*f[now]*(f[to]+1)%p;
	}
}
void dfs1(int now,int father,int val)
{
	f[now]=1LL*f[now]*val%p;
	vector<int>son,pre,suf;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		son.push_back(to);
		pre.push_back(1);
		suf.push_back(1);
	}
	for (int i=1;i<(int)son.size();i++) pre[i]=1LL*pre[i-1]*(f[son[i-1]]+1)%p;
	for (int i=(int)son.size()-2;i>=0;i--) suf[i]=1LL*suf[i+1]*(f[son[i+1]]+1)%p;
	for (int i=0;i<(int)son.size();i++)
	dfs1(son[i],now,(1LL*pre[i]*suf[i]%p*val%p+1)%p);
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read();
	for (int i=2;i<=n;i++)
	{
		int fa=read();
		add_edge(fa,i);
		add_edge(i,fa);
	}
	dfs0(1,0);
	dfs1(1,0,1);
	for (int i=1;i<=n;i++) print(f[i]," \n"[i==n]);
	
	return 0;
}