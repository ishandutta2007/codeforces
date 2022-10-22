// Author: Little09
// Problem: CF1149D Abandoning Roads
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1149D
// Memory Limit: 500 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
#define mem(x) memset(x,0,sizeof(x))
int n,m,A,B;
const int N=72,M=412,SIZ=(1<<17)+50;
int h[N],nxt[M],t[M],w[M],cnt;
inline void add(int x,int y,int z)
{
	t[++cnt]=y;
	w[cnt]=z;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
bool used[N];
int col,num,c[N],dp[SIZ][N],ans[N];
bool vis[SIZ][N];
void dfs1(int x)
{
	num++,used[x]=1;
	for (int i=h[x];i;i=nxt[i])
	{
		if (used[t[i]]||w[i]==B) continue;
		dfs1(t[i]);
	}
}
void dfs2(int x)
{
	c[x]=col;
	for (int i=h[x];i;i=nxt[i])
	{
		if (c[t[i]]||w[i]==B) continue;
		dfs2(t[i]);
	}
}

struct point
{
	int s,u,val;
	bool operator < (const point &o) const
	{
		return val>o.val;
	}
};
priority_queue<point>q;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> A >> B;
	for (int i=1;i<=m;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		add(x,y,z),add(y,x,z);
	}
	mem(used);
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		num=0;
		dfs1(i);
		if (num>=4) 
		{
			++col;
			dfs2(i);
		}
	}
	int bas=col;
	mem(used);
	for (int i=1;i<=n;i++)
	{
		if (used[i]) continue;
		num=0;
		dfs1(i);
		if (num<4) 
		{
			++col;
			dfs2(i);
		}
	}
	// for (int i=1;i<=n;i++) cout << c[i] << " ";
	// cout << endl;
	// cout << bas << endl;
	memset(dp,0x3f,sizeof(dp));
	q.push({0,1,0});
	dp[0][1]=0;
	while (!q.empty())
	{
		point u=q.top();
		q.pop();
		if (vis[u.s][u.u]) continue;
		vis[u.s][u.u]=1;
		//cout << u.s << " " << u.u << endl;
		for (int i=h[u.u];i;i=nxt[i])
		{
			if (c[u.u]==c[t[i]]&&w[i]==B) continue;
			if (c[t[i]]<=bas&&(u.s&(1<<(c[t[i]]-1)))) continue;
			point v=u;
			v.u=t[i],v.val+=w[i];
			//v.val=dp[u.s][u.u]+w[i];
			if (c[u.u]<=bas&&c[u.u]!=c[t[i]]) v.s|=(1<<(c[u.u]-1));
			if (dp[v.s][v.u]>v.val)
			{
				dp[v.s][v.u]=v.val;
				//if (!vis[v.s][v.u])
				q.push(v);
			}
		}
	}
	for (int i=2;i<=n;i++) ans[i]=inf;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<(1<<bas);j++)
		{
			ans[i]=min(ans[i],dp[j][i]);
		}
	}
	for (int i=1;i<=n;i++) cout << ans[i] << " ";
	return 0;
}