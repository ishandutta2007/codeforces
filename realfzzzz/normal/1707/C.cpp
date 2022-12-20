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
const int maxn=1e5+5;
int n,m,p[maxn];
int find(int u){
	return p[u]==u?u:p[u]=find(p[u]);
}
vector<int> g[maxn],g2[maxn];
int fa[maxn],pos[maxn],cnt=0,sz[maxn];
void dfs1(int u){
	pos[u]=cnt++;
	sz[u]=1;
	for(int v:g[u]) if(v!=fa[u]){
		fa[v]=u;
		g2[u].push_back(v);
		dfs1(v);
		sz[u]+=sz[v];
	}
}
bool in(int x,int y){
	return pos[y]>=pos[x]&&pos[y]<pos[x]+sz[x];
}
int c[maxn];
void dfs2(int u){
	c[u]+=c[fa[u]];
	for(int v:g2[u]) dfs2(v);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++) p[i]=i;
	vector<pair<int,int>> vec;
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();
		v=read();
		if(find(u)!=find(v)){
			g[u].push_back(v);
			g[v].push_back(u);
			p[p[u]]=v;
		}
		else vec.push_back({u,v});
	}
	dfs1(1);
	for(auto x:vec){
		int u=x.first,v=x.second;
		if(in(v,u)) swap(u,v);
		if(in(u,v)){
			c[1]++;
			c[*--upper_bound(g2[u].begin(),g2[u].end(),v,[](int x,int y){
				return pos[x]<pos[y];
			})]--;
			c[v]++;
		}
		else{
			c[u]++;
			c[v]++;
		}
	}
	dfs2(1);
	for(int i=1;i<=n;i++) printf("%d",c[i]==m-n+1);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}