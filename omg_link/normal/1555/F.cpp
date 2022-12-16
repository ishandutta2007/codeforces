#include <stdio.h>
#include <vector>
#define MN 300000
#define MM 500000

using std::swap;
using std::vector;

int n,m;

struct Edge{
	int u,v,w,ans;
}a[MM+5];

struct edge{
	int v,w;
};

int uf[MN+5];

vector<edge> e[MN+5];

int dep[MN+5],fa[MN+5][20],xs[MN+5];
int dfl[MN+5],dfr[MN+5],dfc;

int gf(int u){
	return uf[u]==u?u:uf[u]=gf(uf[u]);
}

bool unite(int u,int v){
	u = gf(u);
	v = gf(v);
	if(u==v) return false;
	uf[v] = u;
	return true;
}

void add(int u,int v,int w){
	e[u].push_back({v,w});
}

void dfs(int u){
	dfl[u] = ++dfc;
	for(int i=0;i<19;i++)
		if(fa[u][i])
			fa[u][i+1] = fa[fa[u][i]][i];
		else
			break;
	for(edge E:e[u]){
		int v = E.v;
		if(v==fa[u][0]) continue;
		dep[v] = dep[u]+1;
		fa[v][0] = u;
		xs[v] = xs[u]^E.w;
		dfs(v);
	}
	dfr[u] = dfc;
}

int lca(int u,int v){
	if(dep[u]<dep[v])
		swap(u,v);
	for(int i=0,d=(dep[u]-dep[v]);d;i++)
		if(d&(1<<i)){
			u = fa[u][i];
			d ^= 1<<i;
		}
	if(u==v) return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i]){
			u = fa[u][i];
			v = fa[v][i];
		}
	return fa[u][0];
}

int T[MN*4+5];

void modify(int k,int l,int r,int L,int R,int w){
	if(l==L&&r==R){
		T[k] += w;
		return;
	}
	int mid = (l+r)>>1;
	if(R<=mid) modify(k<<1,l,mid,L,R,w);
	else if(L>mid) modify(k<<1|1,mid+1,r,L,R,w);
	else modify(k<<1,l,mid,L,mid,w),modify(k<<1|1,mid+1,r,mid+1,R,w);
}

int query(int k,int l,int r,int p){
	if(l==r) return T[k];
	int mid = (l+r)>>1;
	if(p<=mid) return query(k<<1,l,mid,p)+T[k];
	else return query(k<<1|1,mid+1,r,p)+T[k];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		uf[i] = i;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
		if(unite(a[i].u,a[i].v)){
			add(a[i].u,a[i].v,a[i].w);
			add(a[i].v,a[i].u,a[i].w);
			a[i].ans = 1;
		}
	}
	for(int i=1;i<=n;i++)
		if(!dep[i]){
			dep[i] = 1;
			dfs(i);
		}
	for(int i=1;i<=m;i++){
		if(a[i].ans) continue;
		if((xs[a[i].u]^xs[a[i].v]^a[i].w)==0){
			a[i].ans = 2;
			continue;
		}
		int u = a[i].u;
		int v = a[i].v;
		int o = lca(u,v);
		if(query(1,1,n,dfl[u])+query(1,1,n,dfl[v])-2*query(1,1,n,dfl[o])){
			a[i].ans = 2;
			continue;
		}
		a[i].ans = 1;
		for(;u!=o;u=fa[u][0])
			modify(1,1,n,dfl[u],dfr[u],1);
		for(;v!=o;v=fa[v][0])
			modify(1,1,n,dfl[v],dfr[v],1);
	}
	for(int i=1;i<=m;i++){
		if(a[i].ans==1)
			puts("YES");
		if(a[i].ans==2)
			puts("NO");
	}
}