#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int n;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

struct graph
{
	struct edge
	{
		int to,next;
	}e[M<<1];int cnt,head[M];
	int size[M],in[M],vis[M];
	void add(int u,int to)
	{
		e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;
		in[u]++;
	}
	void clear()
	{
		for (int i=1;i<=cnt;i++)
			e[i].to=e[i].next=0;
		for (int i=1;i<=n;i++)head[i]=in[i]=vis[i]=size[i]=0;
		cnt=0;
	}
	void topo()
	{
		queue<int> q;
		for (int i=1;i<=n;i++)
		{
			vis[i]=1;
			if (in[i]==1)q.push(i);
		}
		while(!q.empty())
		{
			int k=q.front();q.pop();
			vis[k]=0;
			for (int i=head[k];i;i=e[i].next)
			{
				int to=e[i].to;
				if (vis[to])
				{
					in[to]--;
					if (in[to]==1)q.push(to);
				}
			}
		}
//		for (int i=1;i<=n;i++)cout<<vis[i]<<' ';
//		cout<<endl;
	}
	void dfs(int u,int fa)
	{
		size[u]=1;
		for (int i=head[u];i;i=e[i].next)
		{
			int to=e[i].to;
			if (!vis[to]&&to!=fa)dfs(to,u),size[u]+=size[to];
		}
	}
}G;

signed main()
{
	int T=read();
	while(T--)
	{
		n=read();
		G.clear();
		for (int i=1;i<=n;i++)
		{
			int a=read(),b=read();
			G.add(a,b),G.add(b,a);
		}
		G.topo();int ans=0;
		for (int i=1;i<=n;i++)
			if (G.vis[i])G.dfs(i,0),ans+=G.size[i]*(G.size[i]-1)/2;
		ans=n*(n-1)-ans;
		cout<<ans<<endl;
	}
	return 0;
}