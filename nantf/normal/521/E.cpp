#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=444444;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	char ch=getchar();bool f=false;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
int n,m,el,head[maxn],to[maxn],nxt[maxn],dfn[maxn],sz[maxn],fa[maxn],dep[maxn],dfs_cnt;
int U[maxn],V[maxn],ncnt,cnt[maxn],at,au,av,bu,bv,ans[3][maxn],al[3],tmp[maxn],tl;
bool ntr[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs1(int u,int f){
	dep[u]=dep[fa[u]=f]+1;
	dfn[u]=++dfs_cnt;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(dfn[v]){
			ntr[i]=true;
			if(dfn[v]<dfn[u]) cnt[u]++,cnt[v]--,U[++ncnt]=u,V[ncnt]=v;
			continue;
		}
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int f){
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f || ntr[i]) continue;
		dfs2(v,u);
		cnt[u]+=cnt[v];
	}
}
int main(){
	read(n);read(m);
	FOR(i,1,m){
		int u,v;
		read(u);read(v);
		add(u,v);add(v,u);
	}
	FOR(i,1,n) if(!dfn[i]) dfs1(i,0),dfs2(i,0);
	FOR(i,1,n) if(cnt[i]>=2){at=i;break;}
	if(!at) return puts("NO"),0;
	puts("YES");
	FOR(i,1,ncnt) if(dfn[U[i]]>=dfn[at] && dfn[U[i]]<=dfn[at]+sz[at]-1 && dfn[fa[at]]>=dfn[V[i]] && dfn[fa[at]]<=dfn[V[i]]+sz[V[i]]-1){
		if(au){bu=U[i];bv=V[i];break;}
		else au=U[i],av=V[i];
	}
	int tau=au,tbu=bu;
	while(tau!=tbu){
		if(dep[tau]<dep[tbu]) swap(tau,tbu);
		tau=fa[tau];
	}
	int lwr=tau,upr=dep[av]<dep[bv]?bv:av;
	for(int i=lwr;i!=upr;i=fa[i]) ans[0][++al[0]]=i;
	ans[0][++al[0]]=upr;
	for(int i=upr;i!=av;i=fa[i]) ans[1][++al[1]]=i;
	ans[1][++al[1]]=av;
	for(int i=au;i!=lwr;i=fa[i]) ans[1][++al[1]]=i;
	ans[1][++al[1]]=lwr;
	for(int i=1,j=al[1];i<j;i++,j--) swap(ans[1][i],ans[1][j]);
	for(int i=upr;i!=bv;i=fa[i]) ans[2][++al[2]]=i;
	ans[2][++al[2]]=bv;
	for(int i=bu;i!=lwr;i=fa[i]) ans[2][++al[2]]=i;
	ans[2][++al[2]]=lwr;
	for(int i=1,j=al[2];i<j;i++,j--) swap(ans[2][i],ans[2][j]);
	FOR(i,0,2){
		printf("%d ",al[i]);
		FOR(j,1,al[i]) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}
// stO stO stO stO