// Author: Little09
// Problem: F. Gardener Alex
// Contest: Codeforces Round #586 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1220/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#include <bits/stdc++.h>
using namespace std;
 
const int N=200005;
int n,m; 
int c[N];
	int a[N],p[N];
	int f[N][21];
	int cnt;
	inline void addA(int x)
	{
		a[++cnt]=x;
	}
	void STwork()
	{
		for (int i=1;i<=n;i++) f[i][0]=a[i];
		int t=log2(n);
		for (int i=1;i<=t;i++)
		{
			for (int j=1;j<=n-(1<<i)+1;j++)
			{
				f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
			}
		}
	}
	int STquery(int l,int r)
	{
		int t=log2(r-l+1);
		return min(f[l][t],f[r-(1<<t)+1][t]);
	}
vector<int>t[N];
int rt;
inline void addedge(int x,int y)
{
	if (x==-1) 
	{
		rt=y;
		return;
	}
	t[x].push_back(y);
}
void build(int u,int l,int r)
{
	if (l>r) return;
	int v=p[STquery(l,r)];
	addedge(u,v);
	build(v,l,v-1);
	build(v,v+1,r);
}
int dfn[N],rk[N],siz[N],tot,dis[N];
 
int sum[N*4],add[N*4];
inline void push_up(int u)
{
	sum[u]=max(sum[u*2],sum[u*2+1]);
}
inline void push_down(int u)
{
	if (add[u]!=0)
	{
		sum[u*2]+=add[u];
		sum[u*2+1]+=add[u];
		add[u*2]+=add[u];
		add[u*2+1]+=add[u];
		add[u]=0;
	}
}
void buildD(int u,int l,int r)
{
	// cout << l << " " << r << endl;
	// cout << u << " " <<  sum[u] << endl;
	if (l==r)
	{
		sum[u]=dis[rk[l]];
		return;
	}
	int mid=(l+r)>>1;
	buildD(u*2,l,mid);
	buildD(u*2+1,mid+1,r);
	push_up(u);
}
void change(int u,int L,int R,int l,int r,int k)
{
	if (l<=L&&R<=r) 
	{
		sum[u]+=k;
		add[u]+=k;
		return;
	}
	int mid=(L+R)>>1;
	push_down(u);
	if (l<=mid) change(u*2,L,mid,l,r,k);
	if (mid<r) change(u*2+1,mid+1,R,l,r,k);
	push_up(u);
}
void update(int u,int k)
{
	change(1,1,n-1,dfn[u],dfn[u]+siz[u]-1,k);
}
void dfs(int x)
{
	dfn[x]=++tot,rk[tot]=x;
	siz[x]=1;
	for (int i:t[x])
	{
		dis[i]=dis[x]+1;
		dfs(i);
		siz[x]+=siz[i];
	}
}
int ansx[N],ansy[N];
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	if (n==1)
	{
		cout << "1 0";
		return 0;
	}
	for (int i=1;i<=n;i++) cin >> c[i];
	// n=2e5;
	// for (int i=1;i<=n;i++) c[i]=n+1-i;
	int u;
	for (int i=1;i<=n;i++) if (c[i]==1) u=i;
	for (int i=u+1;i<=n;i++) addA(c[i]);
	for (int i=1;i<u;i++) addA(c[i]);
	STwork();
	for (int i=1;i<n;i++) p[a[i]]=i;
	build(-1,1,n-1);
	dis[rt]=1;
	dfs(rt);
	buildD(1,1,n-1);
	// for (int i=1;i<n;i++) cout << dis[i] << " ";
	// cout << endl;
	// cout << sum[1] << endl;
	ansx[0]=sum[1];
	for (int i=1;i<n;i++)
	{
		update(i,-1);
		ansx[i]=sum[1];
	}
	for (int i=1;i<n;i++)
	{
		update(i,1);
	}
	int uu=0;
	ansy[0]=sum[1];
	for (int i=n-1;i>=1;i--)
	{
		update(i,-1);
		++uu;
		ansy[uu]=sum[1];
	}
	// for (int i=1;i<n;i++) cout << ansx[i] << " ";
	// cout << endl;
	// for (int i=1;i<n;i++) cout << ansy[i] << " ";
	// cout << endl;
	int ans=n+1,ansid=-1,to=0;
	for (int i=u-1;i>=0;i--)
	{
		int res=max(ansx[n-1-i],ansy[i])+1;
		//cout << "5ak " << i << " " << ansx[n-1-i] << " " << ansy[i] << endl;
		if (res<ans) ans=res,ansid=to;
		to++;
	}
	for (int i=n-1;i>=u;i--)
	{
		int res=max(ansx[n-1-i],ansy[i])+1;
		//cout << "5ak " << i << " " << ansx[n-1-i] << " " << ansy[i] << endl;
		if (res<ans) ans=res,ansid=to;
		to++;
	}
	cout << ans << " " << ansid << endl;
	return 0;
}