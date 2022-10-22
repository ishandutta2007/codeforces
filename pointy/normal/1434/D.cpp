// Author: Little09
// Problem: D. Roads and Ramen
// Contest: Codeforces Round #679 (Div. 1, based on Technocup 2021 Elimination Round 1)
// URL: https://codeforces.com/contest/1434/problem/D
// Memory Limit: 512 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=1e6+5;
const int inf=1e8;
int n,m;
struct point
{
	int x[2],y[2],xy[2],yz[2],xyz[2];
	point(){x[0]=-inf,y[0]=-inf,xy[0]=-inf,yz[0]=-inf,xyz[0]=-inf;x[1]=-inf,y[1]=-inf,xy[1]=-inf,yz[1]=-inf,xyz[1]=-inf;}
}s[N*4];
int add[N*4],d[N],dis[N],fz[N];
point operator + (const point &u,const point &v)
{
	point res;
	for (int i=0;i<=1;i++)
	{
		res.x[i]=max(u.x[i],v.x[i]),res.y[i]=max(u.y[i],v.y[i]);
		res.xy[i]=max(u.xy[i],max(v.xy[i],u.x[i]+v.y[i]));
		res.yz[i]=max(u.yz[i],max(v.yz[i],u.y[i]+v.x[i]));
		res.xyz[i]=max(u.xyz[i],max(v.xyz[i],max(u.x[i]+v.yz[i],u.xy[i]+v.x[i])));	
	}
	return res;
}
point change(point u)
{
	point res;
	for (int i=0;i<=1;i++)
	{
		res.x[i]=u.x[i^1],res.y[i]=u.y[i^1];
		res.xy[i]=u.xy[i^1];
		res.yz[i]=u.yz[i^1];
		res.xyz[i]=u.xyz[i^1];	
	}
	return res;
}
inline void push_down(int u)
{
	if (add[u]==0) return;
	s[u*2]=change(s[u*2]),s[u*2+1]=change(s[u*2+1]);
	add[u*2]^=add[u],add[u*2+1]^=add[u];
	add[u]=0;
}
void build(int u,int l,int r)
{
	if (l==r)
	{
		//cout << l << " " << fz[l] << " " << d[l] << endl;
		s[u].x[fz[l]]=d[l],s[u].y[fz[l]]=-2*d[l],s[u].y[fz[l]^1]=-2*d[l];
		s[u].xy[fz[l]]=-d[l],s[u].yz[fz[l]]=-d[l],s[u].xyz[fz[l]]=0;
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid),build(u*2+1,mid+1,r);
	s[u]=s[u*2]+s[u*2+1];
}
void update(int u,int L,int R,int l,int r)
{
	if (l<=L&&R<=r)
	{
		s[u]=change(s[u]),add[u]^=1;
		return;
	}
	push_down(u);
	int mid=(L+R)>>1;
	if (l<=mid) update(u*2,L,mid,l,r);
	if (mid<r) update(u*2+1,mid+1,R,l,r);
	s[u]=s[u*2]+s[u*2+1];
}

int v[N];
int t[N],nxt[N],h[N],cnt,id[N];
inline void addedge(int x,int y,int z,int i)
{
	t[++cnt]=y;
	v[cnt]=z,id[cnt]=i;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
int p[N],deth[N];
int tot,rk[N],siz[N],w[N];

void dfs(int x,int f)
{
	d[++tot]=deth[x],fz[tot]=dis[x],rk[x]=tot,siz[x]=1;
	//cout << x << endl;
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]==f) continue;
		deth[t[i]]=deth[x]+1,dis[t[i]]=(dis[x]^v[i]),w[id[i]]=t[i],p[id[i]]=v[i];
		dfs(t[i],x);
		siz[x]+=siz[t[i]];
		d[++tot]=deth[x],fz[tot]=dis[x];
		//cout << x << endl;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i=1;i<n;i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		addedge(x,y,z,i),addedge(y,x,z,i);
		//cout << x << " " << y << " " << z << endl;
	}
	cin >> m;
	//cout << m << endl;
	dfs(1,0);
	build(1,1,tot);
	//cout << max(s[1].xyz[0],s[1].xyz[1]) << endl;
	int lastans=0;
	for (int i=1;i<=m;i++)
	{
		int d;
		cin >> d;
		//cout << w[d] << endl;
		update(1,1,tot,rk[w[d]],rk[w[d]]+2*siz[w[d]]-2);
		cout << max(s[1].xyz[0],s[1].xyz[1]) << endl;
	}
	return 0;
}