#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int fir[100010],dis[400010],nxt[400010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int dep[100010],st[17][100010],tot[100010],rt[100010];
il vd dfs(int x){
	for(int i=fir[x];i;i=nxt[i])
		if(!dep[dis[i]])
			st[0][dis[i]]=x,rt[dis[i]]=rt[x],dep[dis[i]]=dep[x]+1,dfs(dis[i]);
}
il int LCA(int x,int y){
	if(dep[x]<dep[y])std::swap(x,y);
	for(int i=16;~i;--i)if(dep[st[i][x]]>=dep[y])x=st[i][x];
	for(int i=16;~i;--i)if(st[i][x]!=st[i][y])x=st[i][x],y=st[i][y];
	if(x!=y)x=st[0][x];return x;
}
il vd dfs2(int x){
	for(int i=fir[x];i;i=nxt[i]){
		if(st[0][dis[i]]!=x)continue;
		tot[dis[i]]+=tot[x];
		dfs2(dis[i]);
	}
}
int dfn[100010],low[100010],stk[100010],tp,ins[100010],scc[100010],yes[100010],totscc;
il vd tarjan(int x,int fa=-1){
	dfn[x]=low[x]=++dfn[0];
	stk[++tp]=x;ins[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa)continue;
		if(!dfn[dis[i]])tarjan(dis[i],x),low[x]=std::min(low[x],low[dis[i]]);
		else low[x]=std::min(low[x],dfn[dis[i]]);
	}
	if(dfn[x]==low[x]){
		++totscc;
		while(stk[tp+1]!=x)ins[stk[tp]]=0,scc[stk[tp]]=totscc,--tp;
	}
}
int main(){
	int n=gi(),m=gi(),a,b;
	for(int i=1;i<=m;++i)a=gi(),b=gi(),link(a,b),link(b,a);
	for(int i=1;i<=n;++i)if(!dep[i])dep[i]=1,rt[i]=i,dfs(i);
	for(int i=1;i<17;++i)
		for(int j=1;j<=n;++j)
			st[i][j]=st[i-1][st[i-1][j]];
	for(int i=1;i<=n;++i)if(dep[i]==1)tarjan(i);
	for(int x=1;x<=n;++x){
		for(int i=fir[x];i;i=nxt[i]){
			if((dep[x]+dep[dis[i]])&1)continue;
			if(x>=dis[i])continue;
			if(scc[x]!=scc[dis[i]])continue;
			yes[scc[x]]=1;
		}
	}
	for(int x=1;x<=n;++x)if(st[0][x]&&scc[x]==scc[st[0][x]]&&yes[scc[x]])++tot[x];
	for(int i=1;i<=n;++i)if(dep[i]==1)dfs2(i);
	int Q=gi(),x,y,lca;
	while(Q--){
		x=gi(),y=gi();
		if(rt[x]!=rt[y]||x==y){puts("No");continue;}
		lca=LCA(x,y);
		if(tot[x]+tot[y]-2*tot[lca]||(dep[x]+dep[y])&1)puts("Yes");
		else puts("No");
	}
	return 0;
}