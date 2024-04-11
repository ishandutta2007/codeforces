#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=400040;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,q,U[maxn],V[maxn],el=1,head[maxn],to[maxn],nxt[maxn];
int id[maxn],dfn[maxn],low[maxn],cnt,tot,stk[maxn],tp;
int fa[maxn],dep[maxn],sz[maxn],son[maxn],top[maxn],s1[maxn],s2[maxn];
map<PII,bool> vis;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	stk[++tp]=u;
	dfn[u]=low[u]=++cnt;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(i==(f^1)) continue;
		if(dfn[v]) low[u]=min(low[u],low[v]);
		else dfs(v,i),low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u]){
		tot++;
		do{
			id[stk[tp]]=tot;
		}while(stk[tp--]!=u); 
	}
}
void dfs2(int u,int f){
	dfn[u]=1;
	dep[u]=dep[fa[u]=f]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs2(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs3(int u,int topf){
	top[u]=topf;
	if(son[u]) dfs3(son[u],topf);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs3(v,v);
	}
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
void dfs4(int u){
	dfn[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		dfs4(v);
		s1[u]+=s1[v];
		s2[u]+=s2[v];
	}
}
int main(){
	n=read();m=read();q=read();
	FOR(i,1,m){
		U[i]=read();V[i]=read();
		add(U[i],V[i]);add(V[i],U[i]);
	}
	FOR(i,1,n) if(!dfn[i]) dfs(i,0);
	MEM(head,0);MEM(to,0);MEM(nxt,0);
	el=0;
	FOR(i,1,m){
		int u=id[U[i]],v=id[V[i]];
		if(u!=v && !vis[MP(u,v)]){
			vis[MP(u,v)]=vis[MP(v,u)]=true;
			add(u,v);add(v,u);
		}
	}
	MEM(dfn,0);
	FOR(i,1,cnt) if(!dfn[i]) dfs2(i,0),dfs3(i,i);
	while(q--){
		int u=id[read()],v=id[read()];
		int l=lca(u,v);
		s1[u]++;s1[l]--;
		s2[v]++;s2[l]--;
	}
	MEM(dfn,0);
	FOR(i,1,cnt) if(!dfn[i]) dfs4(i);
	FOR(i,1,cnt) if(s1[i] && s2[i]) return puts("No"),0;
	puts("Yes");
}