#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
typedef long long ll;
int n,c[maxn],el,head[maxn],to[maxn*2],nxt[maxn*2],sz[maxn],son[maxn],fa[maxn],sum[maxn];
ll ans[maxn],tot,mxs;
bool nouse[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs1(int u){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int val){
	sum[c[u]]+=val;
	if(val>0 && sum[c[u]]>mxs) tot=c[u],mxs=sum[c[u]];
	else if(val>0 && sum[c[u]]==mxs) tot+=c[u];
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u] || nouse[v]) continue;
		dfs2(v,val);
	}
}
void dfs3(int u,bool keep){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs3(v,false);
	}
	if(son[u]) dfs3(son[u],true),nouse[son[u]]=true;
	dfs2(u,1);ans[u]=tot;
	if(son[u]) nouse[son[u]]=false;
	if(!keep) dfs2(u,-1),mxs=tot=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",c+i);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	dfs1(1);dfs3(1,true);
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
}