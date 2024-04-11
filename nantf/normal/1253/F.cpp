#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=600060;
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
struct node{
	ll d;
	int id;
	bool operator<(const node &nd)const{return d>nd.d;}
};
struct edge{
	int u,v;
	ll w;
	bool operator<(const edge &e)const{return w<e.w;}
}e[maxn];
int n,m,k,q,el,head[maxn],to[maxn],nxt[maxn],w[maxn],u_fa[maxn];
int cnt,el2,head2[maxn],to2[maxn],nxt2[maxn],fa[maxn],sz[maxn],son[maxn],top[maxn],dep[maxn];
ll wnd[maxn],dis[maxn];
priority_queue<node> pq;
inline void add(int u,int v,int w_){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=w_;
}
inline void add2(int u,int v){
	to2[++el2]=v;nxt2[el2]=head2[u];head2[u]=el2;
}
int getfa(int x){
	return x==u_fa[x]?x:u_fa[x]=getfa(u_fa[x]);
}
void dfs1(int u,int f){
	sz[u]=1;
	dep[u]=dep[fa[u]=f]+1;
	for(int i=head2[u];i;i=nxt2[i]){
		int v=to2[i];
		if(v==f) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v; 
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(son[u]) dfs2(son[u],topf);
	for(int i=head2[u];i;i=nxt2[i]){
		int v=to2[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
int main(){
	n=read();m=read();k=read();q=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
		e[i]=(edge){u,v,w};
	}
	MEM(dis,0x3f);
	FOR(i,1,k) pq.push((node){dis[i]=0,i});
	while(!pq.empty()){
		ll d=pq.top().d;
		int u=pq.top().id;
		pq.pop();
		if(d!=dis[u]) continue;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>d+w[i]) pq.push((node){dis[v]=d+w[i],v});
		}
	}
	FOR(i,1,m) e[i].w+=dis[e[i].u]+dis[e[i].v];
	sort(e+1,e+m+1);
	FOR(i,1,2*n) u_fa[i]=i;
	cnt=n;
	FOR(i,1,m){
		int u=e[i].u,v=e[i].v;
		ll w=e[i].w;
		u=getfa(u);v=getfa(v);
		if(u==v) continue;
		u_fa[u]=u_fa[v]=++cnt;
		wnd[cnt]=w;
		add2(cnt,u);add2(cnt,v);
	}
	dfs1(cnt,0);dfs2(cnt,cnt); 
	while(q--){
		int u=read(),v=read();
		printf("%lld\n",wnd[lca(u,v)]);
	}
}