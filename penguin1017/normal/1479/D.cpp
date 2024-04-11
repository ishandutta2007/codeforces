#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
using namespace std;
const int N=3e5+9;
struct node{
	int l,r;
	ll sum;
	node(int l=0,int r=0,ll sum=0):l(l),r(r),sum(sum){}
}T[N*40];
ll v[N],c;
int newnode(){
	return ++c;
}
int a[N];
void insert(int p1,int p2,int l,int r,int x){
	T[p1].sum=T[p2].sum^v[x];
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m){
		T[p1].r=T[p2].r;
		T[p1].l=newnode();
		insert(T[p1].l,T[p2].l,l,m,x);
	}
	else{
		T[p1].l=T[p2].l;
		T[p1].r=newnode();
		insert(T[p1].r,T[p2].r,m+1,r,x);
	}
}
vector<int> g[N];
#define pb push_back
int fa[N],dep[N],top[N],sz[N];
void dfs(int u){
	sz[u]=1;
	for(auto v:g[u]){
		if(v==fa[u])continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		sz[u]+=sz[v];
	}
}
int n;
void dfs2(int u,int tp){
	insert(u,fa[u],1,n,a[u]);
	top[u]=tp;
	int p=0;
	for(auto v:g[u]){
		if(v==fa[u])continue;
		if(sz[p]<sz[v])p=v;
	}
	if(p)dfs2(p,tp);
	for(auto v:g[u]){
		if(v==fa[u]||v==p)continue;
		dfs2(v,v);
	}
} 
int LCA(int u,int v){
	for(;top[u]!=top[v];u=fa[top[u]]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
	}
	if(dep[u]<dep[v])return u;
	return v;
}
int get(int p1,int p2,int p3,int p4,int l,int r,int L,int R){
	if(!(T[p1].sum^T[p2].sum^T[p3].sum^T[p4].sum)){
		return -1; 
	}
	if(l==r)return l;
	int ans=-1;
	int m=l+r>>1;
	if(L<=m)ans=get(T[p1].l,T[p2].l,T[p3].l,T[p4].l,l,m,L,R);
	if(ans==-1&&R>m)ans=get(T[p1].r,T[p2].r,T[p3].r,T[p4].r,m+1,r,L,R);
	return ans;
}
int main(){
	int q;
	scanf("%d%d",&n,&q);
	c=n;
	rep(i,1,n+1)scanf("%d",&a[i]);
	srand(time(0));
	rep(i,1,n+1){
		v[i]=(1ll*rand()<<40)+(1ll*rand()<<20)+rand();
	}
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	dfs2(1,1);
	rep(i,1,q+1){
		int u,v,l,r;
		scanf("%d%d%d%d",&u,&v,&l,&r);
		int lca=LCA(u,v);
		printf("%d\n",get(u,v,lca,fa[lca],1,n,l,r));
	}
}