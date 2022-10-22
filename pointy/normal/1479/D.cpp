// Author: Little09
// Problem: CF1479D Odd Mineral Resource
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1479D
// Memory Limit: 1000 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=3e5+5;
ull seed='5'+'a'+'b'+'a'+'k'+'i'+'o'+'i';
inline ull random()
{
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}
ull c[N];
int a[N],n,m;
vector<int>t[N];
int fa[N][21],deth[N];

int LCA(int x,int y)
{
	if (deth[x]<deth[y]) swap(x,y);
	for (int i=20;i>=0;i--) if (deth[fa[x][i]]>=deth[y]) x=fa[x][i];
	if (x==y) return x;
	for (int i=20;i>=0;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int tot;
int lc[N*20],rc[N*20],rt[N];
ull sum[N*20];
inline void push_up(int u)
{
	sum[u]=(sum[lc[u]]^sum[rc[u]]);
}
int clone(int u)
{
	++tot;
	lc[tot]=lc[u],rc[tot]=rc[u],sum[tot]=sum[u];
	return tot;
}
int update(int u,int l,int r,int x,ull y)
{
	u=clone(u);
	if (l==r)
	{
		sum[u]^=y;
		return u;
	}
	int mid=(l+r)>>1;
	if (x<=mid) lc[u]=update(lc[u],l,mid,x,y);
	else rc[u]=update(rc[u],mid+1,r,x,y);
	push_up(u);
	return u;
}
int query(int u,int x,int y,int z,int L,int R,int l,int r)
{
	if ((sum[u]^sum[x]^sum[y]^sum[z])==0) return -1;
	if (L==R) return L;
	int mid=(L+R)>>1;
	if (l<=mid)
	{
		int res=query(lc[u],lc[x],lc[y],lc[z],L,mid,l,r);
		if (res!=-1) return res;
	}
	if (mid<r)
	{
		int res=query(rc[u],rc[x],rc[y],rc[z],mid+1,R,l,r);
		if (res!=-1) return res;
	}
	return -1;
}
void dfs(int x,int f)
{
	fa[x][0]=f,deth[x]=deth[f]+1;
	rt[x]=update(rt[f],1,n,a[x],c[a[x]]);
	for (int i=1;i<=20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i:t[x])
	{
		if (i==f) continue;
		dfs(i,x);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i=1;i<=n;i++) c[i]=random();
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		t[x].push_back(y),t[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1;i<=m;i++)
	{
		int u,v,l,r;
		cin >> u >> v >> l >> r;
		int lca=LCA(u,v);
		cout << query(rt[u],rt[v],rt[lca],rt[fa[lca][0]],1,n,l,r) << endl;
	}
	return 0;
}