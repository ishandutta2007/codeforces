#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=888888,mod=998244353;
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
int n,m,q,w[maxn],el,head[maxn],to[maxn],nxt[maxn],dfn[maxn],low[maxn],cnt,stk[maxn],tp,tot;
int el2,head2[maxn],to2[maxn],nxt2[maxn],fa[maxn],sz[maxn],son[maxn],dep[maxn],top[maxn],mn[maxn],id[maxn];
multiset<int> s[maxn];
char op[10];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline void add2(int u,int v){
//	printf("add(%d,%d)\n",u,v);
	to2[++el2]=v;nxt2[el2]=head2[u];head2[u]=el2;
}
void dfs(int u,int f){
//	printf("dfs(%d,%d)\n",u,f);
	dfn[u]=low[u]=++cnt;
	stk[++tp]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		if(!dfn[v]){
			dfs(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){
				tot++;
//				printf("make %d\n",tot);
				do{
					add2(stk[tp],tot);
					add2(tot,stk[tp]);
				}while(stk[tp--]!=v);
				add2(u,tot);
				add2(tot,u);
			}
		}
		else low[u]=min(low[u],dfn[v]);
	}
//	printf("dfn[%d]=%d,low[%d]=%d\n",u,dfn[u],u,low[u]);
}
void dfs1(int u,int f){
	dep[u]=dep[fa[u]=f]+1;
	sz[u]=1;
	for(int i=head2[u];i;i=nxt2[i]){
		int v=to2[i];
		if(v==f) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v; 
	}
}
void dfs2(int u,int topf){
	dfn[u]=++cnt;
	id[cnt]=u;
	top[u]=topf;
	if(son[u]) dfs2(son[u],topf);
	for(int i=head2[u];i;i=nxt2[i]){
		int v=to2[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}
inline void pushup(int o){
	mn[o]=min(mn[o<<1],mn[o<<1|1]);
}
void build(int o,int l,int r){
	if(l==r) return mn[o]=id[l]<=n?w[id[l]]:*s[id[l]].begin(),void();
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(o);
}
void update(int o,int l,int r,int p){
	if(l==r) return mn[o]=id[l]<=n?w[id[l]]:*s[id[l]].begin(),void();
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p);
	else update(rson,p);
	pushup(o);
}
int query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return mn[o];
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	return min(query(lson,ql,qr),query(rson,ql,qr));
}
int query(int u,int v){
	int mn=1e9;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		mn=min(mn,query(1,1,tot,dfn[top[u]],dfn[u]));
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	mn=min(mn,query(1,1,tot,dfn[u],dfn[v]));
	if(u>n) mn=min(mn,w[fa[u]]);
	return mn;
}
int main(){
	n=read();m=read();q=read();
	FOR(i,1,n) w[i]=read();
	FOR(i,1,m){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	tot=n;
	dfs(1,0);
	MEM(dfn,0);cnt=0;
	dfs1(1,0);dfs2(1,1);
	FOR(i,n+1,tot) s[i].insert(1e9);
	FOR(i,1,n) if(fa[i]) s[fa[i]].insert(w[i]);
	build(1,1,tot);
	while(q--){
		scanf("%s",op);
		int x=read(),y=read();
		if(op[0]=='A') printf("%d\n",query(x,y));
		else{
			if(fa[x]) s[fa[x]].erase(s[fa[x]].find(w[x]));
			w[x]=y;
			update(1,1,tot,dfn[x]);
			if(fa[x]){
				s[fa[x]].insert(w[x]);
				update(1,1,tot,dfn[fa[x]]);
			}
		}
	}
}