// By: Little09
// Problem: CF1654G Snowy Mountain
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1654G
// Memory Limit: 1000 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=4e5+5;
int n;
int t[N],nxt[N],h[N],cnt;
int dis[N],w[N],ans[N];
vector<int>p[N],v[N],r[N];
int d[N];
inline void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}

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

queue<int>q;

void bfsA()
{
	for (int i=1;i<=n;i++)
	{
		if (dis[i]==0) q.push(i);
	}
	while (!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=h[x];i;i=nxt[i])
		{
			if (dis[t[i]]!=-1) continue;
			dis[t[i]]=dis[x]+1;
			q.push(t[i]);
		}
	}
}

int tmp[N],tot,a[N];
vector<int>g[N];

void bfsB(int id)
{
	for (int i=1;i<=n;i++) d[i]=n+1;
	for (int i=0;i<p[id].size();i++) d[p[id][i]]=0;
	int nw=id;
	while (r[nw].size()!=0)
	{
		int len=r[nw].size(),op=n+1;
		for (int i=0;i<r[nw].size();i++) 
		{
			op=min(op,d[r[nw][i]]);
			a[r[nw][i]]=n+1;
			if (d[r[nw][i]]==n+1) continue; 
			if (d[r[nw][i]]<=0) a[r[nw][i]]=0,g[0].push_back(r[nw][i]);
			else a[r[nw][i]]=d[r[nw][i]],g[d[r[nw][i]]].push_back(r[nw][i]);
		}
		if (op==n+1) break;
		op=max(op,0);
		for (int i=op;i<=min(n,op+len);i++)
		{
			for (int j=0;j<g[i].size();j++)
			{
				int u=g[i][j];
				if (a[u]<i) continue;
				for (int k=0;k<v[u].size();k++)
				{
					if (a[v[u][k]]>a[u]+1)
					{
						a[v[u][k]]=a[u]+1;
						g[a[u]+1].push_back(v[u][k]);
					}
				}
			}
			g[i].clear();
		}
		for (int i=0;i<r[nw].size();i++) 
		{
			if (d[r[nw][i]]>0) d[r[nw][i]]=a[r[nw][i]];
		}
		for (int i=0;i<r[nw].size();i++) 
		{
			int u=r[nw][i];
			for (int j=h[u];j;j=nxt[j])
			{
				if (dis[t[j]]<=dis[u]) continue;
				if (d[u]!=n+1) d[t[j]]=min(d[u]-1,d[t[j]]);
			}
		}
		nw++;
	}
	for (int i=1;i<=n;i++)
	{
		if (d[i]<=0)
		{
			ans[i]=min(ans[i],id);
		}
	}
}

int main()
{
	n=read();
	memset(dis,-1,sizeof(dis));
	for (int i=1;i<=n;i++) 
	{
		int x=read();
		if (x==1) dis[i]=0;
	}
	for (int i=1;i<n;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	bfsA();
	for (int i=1;i<=n;i++) r[dis[i]].push_back(i);
	for (int i=1;i<=n;i++)
	{
		for (int j=h[i];j;j=nxt[j])
		{
			if (dis[i]==dis[t[j]]) 
			{
				w[i]=1;
				v[i].push_back(t[j]);
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (w[i]==1)
		{
			p[dis[i]].push_back(i);
		}
	}
	for (int i=1;i<=n;i++) ans[i]=n+1;
	for (int i=0;i<=n;i++)
	{
		if (p[i].size()>0) bfsB(i);
	}
	for (int i=1;i<=n;i++) 
	{
		if (ans[i]>n) printf("%d ",dis[i]);
		else printf("%d ",dis[i]*2-ans[i]);
	}
	return 0;
}