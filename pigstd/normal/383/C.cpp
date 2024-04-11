#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int n,q,tag[M],dfn[M],size[M],a[M],t;

int lowbit(int x){return x&(-x);}
struct BIT
{
	int c[M];
	void add(int k,int x)
	{
		for (int i=k;i<=n;i+=lowbit(i))
			c[i]+=x;
	}
	int query(int k)
	{
		int sum=0;
		for (int i=k;i>=1;i-=lowbit(i))
			sum+=c[i];
		return sum;
	}
	int update(int l,int r,int k){add(l,k),add(r+1,-k);}
}T[2];

struct graph
{
	struct edge{int to,next;}e[M<<1];int cnt,head[M];
	void add(int u,int to){e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;}
	void dfs(int u,int fa,int ti)
	{
		dfn[u]=++t,tag[u]=ti,size[u]=1;
		for (int i=head[u];i;i=e[i].next)
			if (e[i].to!=fa)dfs(e[i].to,u,ti^1),size[u]+=size[e[i].to];
	}
}G;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

signed main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),to=read();
		G.add(u,to),G.add(to,u);
	}
	G.dfs(1,0,0);
//	for (int i=1;i<=n;i++)cout<<dfn[i]<<' ';puts("");
	while(q--)
	{                            
		int opt=read();
		if (opt==1)
		{
			int u=read(),val=read();
			T[tag[u]].update(dfn[u],dfn[u]+size[u]-1,val);
			T[tag[u]^1].update(dfn[u],dfn[u]+size[u]-1,-val);
		}
		else
		{
			int u=read();
			printf("%lld\n",T[tag[u]].query(dfn[u])+a[u]);
		}
	}
	return 0;
}