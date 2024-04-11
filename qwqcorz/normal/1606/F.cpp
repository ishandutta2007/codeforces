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
vector<int>e[N];
vector<int>f[N],g[N];
int deg[N],sum[N];
void dfs(int now,int father)
{
	int mx=1;
	for (int to:e[now])
	{
		if (to==father) continue;
		dfs(to,now);
		deg[now]++;
		mx=max(mx,(int)g[to].size());
	}
	mx=max(mx,deg[now]);
	g[now].resize(mx);
	for (int i=0;i<mx;i++) g[now][i]=-i;
	for (int to:e[now])
	{
		if (to==father) continue;
		for (int i=0;i<(int)g[to].size();i++) g[now][i]+=g[to][i];
		sum[g[to].size()]++;
	}
	for (int i=0;i<mx;i++) g[now][i]+=sum[i]+=i?sum[i-1]:0;
	for (int i=0;i<mx;i++) f[now].push_back(g[now][i]+i);
	while (!g[now].empty()&&g[now].back()<1) g[now].pop_back();
	for (int i=0;i<=mx;i++) sum[i]=0;
}
void Multi_test_no_horses()
{
	int n=read();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	int Q=read();
	while (Q--)
	{
		int x=read(),k=read();
		if (k>=(int)f[x].size()) print(deg[x]);
		else print(max(deg[x],f[x][k]));
	}
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}