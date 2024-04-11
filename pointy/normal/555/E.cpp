// By: Little09
// Problem: CF555E Case of Computer Network
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF555E
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int mul[N];
inline int read()
{
    int F=1,ANS=0;
	char C=getchar();
    while (C<'0'||C>'9')
	{
		if (C=='-') F=-1;
		C=getchar();
	}
    while (C>='0'&&C<='9')
	{
		ANS=ANS*10+C-'0';
		C=getchar();
	}
    return F*ANS;
}
int n,m,col,dis[N][2],co[N];
namespace TREE
{
	int cnt,t[N],nxt[N],h[N],c[N],COL;
	int deth[N],fa[N][22];
	void add(int x,int y)
	{
		cnt++;
		t[cnt]=y;
		nxt[cnt]=h[x];
		h[x]=cnt;
	}
	void dfs(int u,int f)
	{
		deth[u]=deth[f]+1;
		fa[u][0]=f;
		c[u]=COL;
		for (int i=1;i<=20;i++)
		{
			fa[u][i]=fa[fa[u][i-1]][i-1];
		} 
		for (int i=h[u];i;i=nxt[i])
		{
			if (t[i]!=f) dfs(t[i],u);
		}
	}
	int LCA(int x,int y)
	{
		if (deth[x]<deth[y]) swap(x,y);
		for (int i=20;i>=0;i--) if (deth[fa[x][i]]>=deth[y]) x=fa[x][i];
	    if (x==y) return x;
	    for (int i=20;i>=0;i--)
	    {
	    	if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	    }
	    return fa[x][0];
	}
	void update(int u,int f)
	{
		for (int i=h[u];i;i=nxt[i])
		{
			if (t[i]!=f) 
			{
				update(t[i],u);
				dis[u][0]+=dis[t[i]][0];
				dis[u][1]+=dis[t[i]][1];
			}
		}
	}
	bool check()
	{
		for (int i=1;i<=col;i++)
		{
			if (deth[i]==1) update(i,0);
		}
		for (int i=1;i<=col;i++)
		{
			if (deth[i]==1) continue;
			if (dis[i][0]==0||dis[i][1]==0);
			else return 0;
		} 
		return 1;
	}
	void work()
	{
		for (int i=1;i<=col;i++)
		{
			if (c[i]==0) COL++,dfs(i,0);
		}
	}
}
namespace TARJAN
{
	int cnt=1,num,ans,res;
	int h[N],nxt[N],t[N];
	int dfn[N],low[N],st[N],top=0;
	int d[N];
	bool cut[N];
	void add(int x,int y)
	{
		cnt++;
		t[cnt]=y;
		nxt[cnt]=h[x];
		h[x]=cnt;
	}
	void tarjan(int u,int in)
	{
		dfn[u]=low[u]=++num;
		for (int i=h[u];i!=0;i=nxt[i])
		{
			int v=t[i];
			if (!dfn[v])
			{
				tarjan(v,i);
				low[u]=min(low[u],low[v]);
				if (low[v]>dfn[u]) cut[i]=1,cut[i^1]=1;
			}
			else if (i!=(in^1))
			{
				low[u]=min(low[u],dfn[v]);
			}
		}
	}	
	void dfs(int x)
	{
		co[x]=col;
		for (int i=h[x];i;i=nxt[i])
		{
			int v=t[i];
			if (cut[i]==0&&co[v]==0) dfs(t[i]);
		}
	}
	void work()
	{
		for (int i=1;i<=n;i++)
		{
			if (!dfn[i]) tarjan(i,0);
		}
		for (int i=1;i<=n;i++)
		{
			if (co[i]==0) 
			{
				col++;
				dfs(i);
			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=h[i];j;j=nxt[j])
			{
				if (co[i]==co[t[j]]) continue;
				TREE::add(co[i],co[t[j]]);
				//cout << co[i] << " " << co[t[j]] << endl;
			}
		}
	}
}

int main()
{
	n=read(),m=read();
	int q=read();
	for (int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		TARJAN::add(x,y);
		TARJAN::add(y,x);
	}
	TARJAN::work();
	TREE::work();
	while (q--)
	{
		int x=co[read()],y=co[read()];
		if (x==y) continue;
		if (TREE::c[x]!=TREE::c[y]) 
		{
			puts("No");
			return 0;
		}
		int z=TREE::LCA(x,y);
		dis[x][0]++,dis[z][0]--;
		dis[y][1]++,dis[z][1]--;
	}
	if (TREE::check()) puts("Yes");
	else puts("No");
	return 0;
}