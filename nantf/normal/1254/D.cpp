#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030,mod=998244353;
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
int n,q,el,head[maxn],to[maxn],nxt[maxn],b[maxn],dep[maxn],sz[maxn],son[maxn],fa[maxn],top[maxn],lft[maxn],rig[maxn],cnt,tag[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
inline void update(int p,int v){
	for(int i=p;i<=n;i+=i&-i) b[i]=(b[i]+v)%mod;
}
inline void update(int l,int r,int v){
	update(l,v);update(r+1,(mod-v)%mod);
}
inline int query(int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s=(s+b[i])%mod;
	return s;
}
void dfs1(int u,int f){
	dep[u]=dep[fa[u]=f]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v; 
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	lft[u]=++cnt;
	if(son[u]) dfs2(son[u],topf);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
	rig[u]=cnt;
}
void update_tree(int u,int d){
	tag[u]=(tag[u]+d)%mod;
	if(son[u]) update(lft[son[u]],rig[son[u]],1ll*(n-sz[son[u]])*d%mod);
	if(u!=1){
		update(1,lft[u]-1,1ll*sz[u]*d%mod);
		if(rig[u]!=n) update(rig[u]+1,n,1ll*sz[u]*d%mod);
	}
}
int query_tree(int u){
	int s=(1ll*n*tag[u]+query(lft[u]))%mod;
	while(u){
		s=(s+1ll*tag[fa[top[u]]]*(n-sz[top[u]]))%mod; 
		u=fa[top[u]];
	}
	return s;
}
int main(){
	n=read();q=read();
	int inv=qpow(n,mod-2);
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs1(1,0);dfs2(1,1);
	while(q--){
		int tp=read(),u=read();
		if(tp==1) update_tree(u,1ll*inv*read()%mod);
		else printf("%d\n",query_tree(u));
	}
}