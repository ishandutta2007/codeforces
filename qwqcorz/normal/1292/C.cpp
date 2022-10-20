#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e3+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
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
struct node
{
	int u,v,lu,lv,len;
	int su,sv;
	bool operator <(const node &a)const
	{
		return len<a.len;
	}
}a[N*N];
int siz[N],fa[N],cnt=0;
ll dp[N][N],ans=0;
void dfs0(int now,int father)
{
	fa[now]=father;
	siz[now]=1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		dfs0(to,now);
		siz[now]+=siz[to];
	}
}
int dfs1(int st,int stsiz,int lu,int now,int father,int len)
{
	int siz=1;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		if (to==father) continue;
		siz+=dfs1(st,stsiz,lu,to,now,len+1);
	}
	a[++cnt]=(node){st,now,lu,father,len,stsiz,siz};
	return siz;
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs0(1,0);
	for (int i=1;i<=n;i++)
	{
		for (int j=head[i];j;j=e[j].nxt)
		{
			int to=e[j].to;
			if (to!=fa[i])
			dfs1(i,n-siz[i]+1,to,to,i,1);
		}
		if (fa[i]) dfs1(i,siz[i],fa[i],fa[i],i,1);
	}
	sort(a+1,a+1+cnt);
	for (int k=1;k<=cnt;k++)
	{
		node i=a[k];
		ans=max(ans,dp[i.u][i.v]=max(dp[i.lu][i.v],dp[i.u][i.lv])+1LL*i.su*i.sv);
	}
	print(ans);
	
	return 0;
}