#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[200010],dis[400010],nxt[400010],id=1;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int dfn[200010],low[200010],stk[200010],tp,ins[200010],bel[200010],scc;
std::set<std::pair<int,int>>newE;
void tarjan(int x,int fa=-1){
	dfn[x]=low[x]=++dfn[0];stk[++tp]=x,ins[x]=tp;
	for(int i=fir[x];i;i=nxt[i]){
		if(!dfn[dis[i]])tarjan(dis[i],i),low[x]=std::min(low[x],low[dis[i]]);
		else if(ins[dis[i]]&&(i^fa^1))low[x]=std::min(low[x],dfn[dis[i]]);
	}
	if(dfn[x]==low[x]){
		++scc;
		while(ins[x])ins[stk[tp]]=0,bel[stk[tp]]=scc,--tp;
	}
}
int fa[200010],siz[200010],top[200010],son[200010],dep[200010];
void dfs(int x){
	siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(fa[x]==dis[i])continue;
		fa[dis[i]]=x;
		dep[dis[i]]=dep[x]+1;
		dfs(dis[i]);
		siz[x]+=siz[dis[i]];
		if(siz[son[x]]<siz[dis[i]])son[x]=dis[i];
	}
}
int LCA(int a,int b){
	while(top[a]^top[b]){
		if(dep[top[a]]<dep[top[b]])std::swap(a,b);
		a=fa[top[a]];
	}
	return dep[a]<dep[b]?a:b;
}
void dfs(int x,int tp){
	top[x]=tp;if(son[x])dfs(son[x],tp);
	for(int i=fir[x];i;i=nxt[i])if(fa[x]!=dis[i]&&son[x]!=dis[i])dfs(dis[i],dis[i]);
}
int c1[200010],c2[200010];
void DFS(int x){
	for(int i=fir[x];i;i=nxt[i]){
		if(fa[x]==dis[i])continue;
		DFS(dis[i]);
		c1[x]+=c1[dis[i]];
		c2[x]+=c2[dis[i]];
	}
	if(c1[x]&&c2[x])puts("No"),exit(0);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),q=gi(),u,v;
	for(int i=1;i<=m;++i)u=gi(),v=gi(),link(u,v),link(v,u);
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;++i)
		for(int j=fir[i];j;j=nxt[j])
			if(i<dis[j]&&bel[i]!=bel[dis[j]])
				newE.insert({bel[i],bel[dis[j]]});
	memset(fir,0,sizeof fir);id=1;
	for(auto[x,y]:newE)link(x,y),link(y,x);
	for(int i=1;i<=scc;++i)if(!dep[i])dep[i]=1,dfs(i),dfs(i,i);
	while(q--){
		u=bel[gi()],v=bel[gi()];int l=LCA(u,v);
		++c1[u],--c1[l];
		++c2[v],--c2[l];
	}
	for(int i=1;i<=scc;++i)if(!fa[i])DFS(i);
	puts("Yes");
	return 0;
}