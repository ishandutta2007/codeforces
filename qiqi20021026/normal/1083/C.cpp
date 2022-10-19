#include<bits/stdc++.h>

using namespace std;

#define N 800000
#define ls (x<<1)
#define rs (x<<1|1)

int n,m,x,y,op,fa[N],d[N],top[N],f[N],a[N],tot,head[N],sz[N];
struct node{
	int l,r,x,y;
	node(int l=0,int r=0,int x=0,int y=0):l(l),r(r),x(x),y(y){}
}s[N];
struct edge{int v,nxt;}e[N];

void add(int x,int y){
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
}

void dfs1(int u){
	d[u]=d[fa[u]]+1;
	for (int i=head[u],v;i;i=e[i].nxt){
		dfs1(v=e[i].v);
		sz[u]+=sz[v];
	}
	if (!sz[u]) ++sz[u];
}

void dfs2(int u){
	if (!top[u]) top[u]=u; int t=0;
	for (int i=head[u],v;i;i=e[i].nxt)
		if (sz[v=e[i].v]>sz[t]) t=v;
	if (!t) return; top[t]=top[u]; dfs2(t);
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=t) dfs2(v);
}

int lca(int u,int v){
	for (;top[u]!=top[v];u=fa[top[u]])
		if (d[top[u]]<d[top[v]]) swap(u,v);
	return d[u]<d[v]?u:v;
}

bool solve(int &x,int &y,int z){
	int xy=lca(x,y),xz=lca(x,z),yz=lca(y,z);
	if ((xy==x&&xz==yz)||(xz==x&&xy==yz)){x=y; y=z; return 1;}
	if ((xy==y&&yz==xz)||(yz==y&&xy==xz)){x=x; y=z; return 1;}
	if ((xz==z&&yz==xy)||(yz==z&&xz==xy)){x=x; y=y; return 1;}
	return 0;
}

node merge(node p,node q){
	if (p.r+1<q.l) return p;
	int x=p.x,y=p.y,z=q.x;
	bool fl=solve(x,y,z);
	if (!fl) return p;
	z=q.y;
	fl=solve(x,y,z);
	if (!fl) return p;
	return node(p.l,q.r,x,y);
}

void build(int x,int l,int r){
	if (l==r){s[x]=node(l,l,f[l],f[l]); return;}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	s[x]=merge(s[ls],s[rs]);
}

void mdf(int x,int l,int r,int t,int k){
	if (l==r){s[x]=node(l,l,k,k); return;}
	int mid=(l+r)>>1;
	if (t<=mid) mdf(ls,l,mid,t,k);
	else mdf(rs,mid+1,r,t,k);
	s[x]=merge(s[ls],s[rs]);
}

int qry(){
	int x=1,l=1,r=n;
	node t=node(1,1,f[1],f[1]);
	while (l<=r){
		if (l==r){t=merge(t,s[x]); break;}
		t=merge(t,s[ls]);
		int mid=(l+r)>>1;
		if (t.r<mid){x=ls; r=mid;}
		else{x=rs; l=mid+1;}
	}
	return t.r;
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){scanf("%d",a+i); ++a[i]; f[a[i]]=i;}
	for (int i=2;i<=n;++i){scanf("%d",fa+i); add(fa[i],i);}
	dfs1(1); dfs2(1);
	build(1,1,n);
	scanf("%d",&m);
	while (m--){
		scanf("%d",&op);
		if (op==1){
			scanf("%d%d",&x,&y);
			swap(a[x],a[y]);
			mdf(1,1,n,a[x],x);
			mdf(1,1,n,a[y],y);
			f[a[x]]=x; f[a[y]]=y;
		}
		else printf("%d\n",qry());
	}
	
	return 0;
}