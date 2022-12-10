#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 500005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,k,p[N],u[N],v[N],ty[N],id[N],q,vis[N],fa[N],pos[N];

int Max[N*4],Q[N],tot,st[N],ed[N];

vector<int>edge[N],s[N];

int get(int x){ return x==fa[x]?x:fa[x]=get(fa[x]); }

void Merge(int x,int y,int ti)
{
		x=get(x); y=get(y);
		if (x==y) return;
		fa[x]=y; edge[y].pb(x); s[y].pb(ti);
}

void dfs(int x)
{
		st[x]=++tot; Q[tot]=x;
		int i;
		for (int i=0;i<(int)edge[x].size();++i) dfs(edge[x][i]);
		ed[x]=tot;
}

void build(int l,int r,int t)
{
		if (l==r) Max[t]=p[Q[l]];
		else build(l,mid,ls),build(mid+1,r,rs),Max[t]=max(Max[ls],Max[rs]); 
}

int FindMax(int ll,int rr,int l,int r,int t)
{
		if (ll<=l&&r<=rr) return Max[t];
		int S=-1;
		if (ll<=mid) S=max(S,FindMax(ll,rr,l,mid,ls));
		if (rr>mid)  S=max(S,FindMax(ll,rr,mid+1,r,rs));
		return S; 
}

void update(int c,int ll,int rr,int l,int r,int t)
{
		if (ll<=l&&r<=rr)
		{
				if (Max[t]==c&&l==r) Max[t]=0;
				if (Max[t]!=c) return;
				if (Max[ls]==c) update(c,ll,rr,l,mid,ls);
				else update(c,ll,rr,mid+1,r,rs);
				Max[t]=max(Max[ls],Max[rs]);
		}
		else
		{
				if (ll<=mid) update(c,ll,rr,l,mid,ls);
				if (rr>mid)  update(c,ll,rr,mid+1,r,rs);
				Max[t]=max(Max[ls],Max[rs]); 
		}
}

int main()
{
		scanf("%d%d%d",&n,&m,&q);
		for (i=1;i<=n;++i) scanf("%d",&p[i]),fa[i]=i;
		for (i=1;i<=m;++i) scanf("%d%d",&u[i],&v[i]);
		for (i=1;i<=q;++i) scanf("%d%d",&ty[i],&id[i]);
		for (i=1;i<=q;++i) if (ty[i]==2) vis[id[i]]=1; 
		for (i=1;i<=m;++i) if (vis[i]==0) Merge(u[i],v[i],-1);
		for (i=q;i;--i) if (ty[i]==2) Merge(u[id[i]],v[id[i]],q-i);
		else pos[i]=get(id[i]);
		for (i=1;i<=n;++i) if (fa[i]==i) dfs(i);
		build(1,n,1);
		for (i=1;i<=q;++i) 
			if (ty[i]==1)
			{
				  int p=pos[i];
				  int nw=lower_bound(s[p].begin(),s[p].end(),q-i)-s[p].begin();
				  int Maxn=FindMax(st[p],(nw==0?st[p]:ed[edge[p][nw-1]]),1,n,1);
				  printf("%d\n",Maxn);
				  if (Maxn>0)
				  update(Maxn,st[p],(nw==0?st[p]:ed[edge[p][nw-1]]),1,n,1);
			}
}