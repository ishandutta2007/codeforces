#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2.5e5+5;
int n;
vector<int> g1[maxn],g2[maxn];
int fa[maxn],dep[maxn],sz[maxn],son[maxn];
void dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	sz[u]=1;
	for(int v:g1[u]) if(v!=fa[u]){
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
int top[maxn],pos[maxn];
vector<int> f;
void dfs2(int u){
	top[u]=son[fa[u]]==u?top[fa[u]]:u;
	pos[u]=f.size();
	f.push_back(u);
	if(son[u]) dfs2(son[u]);
	for(int v:g1[u])
		if(v!=fa[u]&&v!=son[u]) dfs2(v);
}
int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int p[maxn];
int find(int u){
	return p[u]==u?u:p[u]=find(p[u]);
}
int get(int x,int y,int u){
	auto c=[u](int x){
		return find(x)==find(u);
	};
	int z=lca(x,y);
	if(c(y)^c(z)) x=y;
	while(top[x]!=top[z]){
		if(c(fa[top[x]])^c(x)) break;
		x=fa[top[x]];
	}
	int l=max(pos[top[x]],pos[z]+1),r=pos[x];
	while(l<r){
		int mid=l+(r-l)/2;
		if(c(f[mid])^c(fa[f[l]])) r=mid;
		else l=mid+1;
	}
	return f[r];
}
void dfs(int u,int f){
	for(int v:g2[u]) if(v!=f) dfs(v,u);
	if(u!=1){
		int x=get(u,f,u);
		printf("%d %d %d %d\n",x,fa[x],u,f);
		p[find(x)]=fa[x];
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		g1[u].push_back(v);
		g1[v].push_back(u);
	}
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		g2[u].push_back(v);
		g2[v].push_back(u);
	}
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;i++) p[i]=i;
	printf("%d\n",n-1);
	dfs(1,0);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}