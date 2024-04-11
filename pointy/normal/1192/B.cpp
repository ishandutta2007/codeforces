// Author: Little09
// Problem: CF1192B Dynamic Diameter
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1192B
// Memory Limit: 1000 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll inf=1e17;
const int N=2e5+5;
int n,m;
ll W;
struct point
{
	ll x,y,xy,yz,xyz;
	point(){x=-inf,y=-inf,xy=-inf,yz=-inf,xyz=-inf;}
}s[N*4];
ll add[N*4],d[N];
point operator + (const point &u,const point &v)
{
	point res;
	res.x=max(u.x,v.x),res.y=max(u.y,v.y);
	res.xy=max(u.xy,max(v.xy,u.x+v.y));
	res.yz=max(u.yz,max(v.yz,u.y+v.x));
	res.xyz=max(u.xyz,max(v.xyz,max(u.x+v.yz,u.xy+v.x)));
	return res;
}
point operator + (const point &u,const ll &v)
{
	point res=u;
	res.x+=v,res.y-=2*v,res.xy-=v,res.yz-=v;
	return res;
}
inline void push_down(int u)
{
	if (add[u]==0) return;
	s[u*2]=s[u*2]+add[u],s[u*2+1]=s[u*2+1]+add[u];
	add[u*2]+=add[u],add[u*2+1]+=add[u];
	add[u]=0;
}
void build(int u,int l,int r)
{
	if (l==r)
	{
		s[u].x=d[l],s[u].y=-2*d[l];
		s[u].xy=-d[l],s[u].yz=-d[l],s[u].xyz=0;
		return;
	}
	int mid=(l+r)>>1;
	build(u*2,l,mid),build(u*2+1,mid+1,r);
	s[u]=s[u*2]+s[u*2+1];
}
void update(int u,int L,int R,int l,int r,ll x)
{
	if (l<=L&&R<=r)
	{
		s[u]=s[u]+x,add[u]+=x;
		return;
	}
	push_down(u);
	int mid=(L+R)>>1;
	if (l<=mid) update(u*2,L,mid,l,r,x);
	if (mid<r) update(u*2+1,mid+1,R,l,r,x);
	s[u]=s[u*2]+s[u*2+1];
}

ll v[N];
int t[N],nxt[N],h[N],cnt,id[N];
inline void addedge(int x,int y,ll z,int i)
{
	t[++cnt]=y;
	v[cnt]=z,id[cnt]=i;
	nxt[cnt]=h[x];
	h[x]=cnt;
}
ll dis[N],p[N];
int tot,rk[N],siz[N],w[N];

void dfs(int x,int f)
{
	d[++tot]=dis[x],rk[x]=tot,siz[x]=1;
	for (int i=h[x];i;i=nxt[i])
	{
		if (t[i]==f) continue;
		dis[t[i]]=dis[x]+v[i],w[id[i]]=t[i],p[id[i]]=v[i];
		dfs(t[i],x);
		siz[x]+=siz[t[i]];
		d[++tot]=dis[x];
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> W;
	for (int i=1;i<n;i++)
	{
		ll x,y,z;
		cin >> x >> y >> z;
		addedge(x,y,z,i),addedge(y,x,z,i);
	}
	dfs(1,0);
	build(1,1,tot);
	ll lastans=0;
	for (int i=1;i<=m;i++)
	{
		ll d,e;
		cin >> d >> e;
		d=(d+lastans)%(n-1)+1;
		e=(e+lastans)%W;
		update(1,1,tot,rk[w[d]],rk[w[d]]+2*siz[w[d]]-2,e-p[d]);
		p[d]=e;
		lastans=s[1].xyz;
		cout << lastans << endl;
	}
	return 0;
}