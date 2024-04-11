// Author: Little09
// Problem: CF914E Palindromes in a Tree
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF914E
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,L,R;
const int N=2e6+5;
int f[N];
int t[N*2],nxt[N*2],h[N],cnt;
int sum,rt;
int siz[N],maxp[N];
ll ans[N],s[N];
bool used[N];
void getrt(int u,int fa)
{
	siz[u]=1,maxp[u]=0;
	for (int i=h[u];i;i=nxt[i])
	{
		int v=t[i];
		if (v==fa||used[v]) continue;
		getrt(v,u);
		siz[u]+=siz[v];
		maxp[u]=max(maxp[u],siz[v]);
	}
	maxp[u]=max(maxp[u],sum-siz[u]);
	if (maxp[u]<maxp[rt]) rt=u;
}
int dis[N],a[N],tot;
int b[N],top;
int g[N],gl[N],tmp;
inline void init()
{
	for (int i=1;i<=tmp;i++) g[gl[i]]=0;
	tmp=0;
}
inline void add(int x)
{
	//if (rt==3) cout << x << endl;
	g[x]++;
	gl[++tmp]=x;
}
inline ask(int x)
{
	int res=g[x];
	for (int i=0;i<20;i++) res+=g[x^(1<<i)];
	return res;
}
void getdis(int u,int fa,int tp)
{
	a[++tot]=dis[u];
	s[u]=ask(dis[u]^f[rt]);
	//if (rt==3) cout << u <<" "<<s[u]<<endl;
	if (tp==0) ans[rt]+=s[u];
	for (int i=h[u];i;i=nxt[i])
	{
		int v=t[i];
		if (used[v]||v==fa) continue;
		dis[v]=(dis[u]^f[v]);
		getdis(v,u,tp);
		s[u]+=s[v];
	}
	ans[u]+=s[u];
}
void calc(int u)
{
	init();
	top=0;
	add(f[u]);
	for (int i=h[u];i;i=nxt[i])
	{
		int v=t[i];
		if (used[v]) continue;
		b[++top]=v;
		//if (rt==3)cout << "v:"<<v << endl;
		tot=0;
		dis[v]=(f[u]^f[v]);
		getdis(v,u,0);
		for (int j=1;j<=tot;j++) add(a[j]);
	}
	init();
	for (int i=top;i>=1;i--)
	{
		int v=b[i];
		tot=0;
		dis[v]=f[v];
		getdis(v,u,1);
		for (int j=1;j<=tot;j++) add(a[j]);
	}
}
void solve(int u)
{
	used[u]=1;
	calc(u);
	for (int i=h[u];i;i=nxt[i])
	{
		int v=t[i];
		if (used[v]) continue;
		sum=siz[v],rt=0;
		getrt(v,0);
		solve(rt);
	}
}
inline void add(int x,int y)
{
	t[++cnt]=y;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=2;i<=n;i++)
	{
		int x,y;
		cin >> x >> y;
		add(x,y),add(y,x);
	}
	for (int i=1;i<=n;i++)
	{
		char x;
		cin >> x;
		f[i]=(1<<(x-'a'));
	}
	maxp[0]=n+1;
	sum=n,rt=0;
	getrt(1,0);
	solve(rt);
	for (int i=1;i<=n;i++) cout << ans[i]+1 << " ";
	return 0;
}