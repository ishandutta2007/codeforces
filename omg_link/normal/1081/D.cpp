#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 100000
#define MM 100000
#define MK 100000
int n,m,k,x[MK+5],fa[MN+5],ans=0;
int hd[MN+5],to[MM*2+5],nxt[MM*2+5],val[MM*2+5];
bool o[MN+5];
struct EDGE{int u,v,w;}e[MM+5];
bool cmp(EDGE a,EDGE b){
	return a.w<b.w;
}
int gf(int u){
	return fa[u]==u?u:fa[u]=gf(fa[u]);
}
bool unite(int u,int v){
	u=gf(u),v=gf(v);
	if(u==v) return false;
	fa[v]=u;
	return true;
}
void add(int u,int v,int w){
	static int rn=0;
	to[rn]=v,nxt[rn]=hd[u],val[rn]=w;
	hd[u]=rn++;
}
bool dfs(int u,int fa){
	bool fl=o[u];
	for(int i=hd[u];~i;i=nxt[i]){
		if(to[i]==fa) continue;
		if(dfs(to[i],u)){
			fl=true;
			ans=std::max(ans,val[i]);
		}
	}
	return fl;
}
int main(){
	memset(hd,0xff,sizeof(hd));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++) scanf("%d",&x[i]),o[x[i]]=true;
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	std::sort(e+1,e+1+m,cmp);
	for(int i=1;i<=m;i++)
		if(unite(e[i].u,e[i].v)){
			add(e[i].u,e[i].v,e[i].w);
			add(e[i].v,e[i].u,e[i].w);
		}
	dfs(x[1],0);
	for(int i=1;i<=k;i++)
		printf("%d ",ans);
}