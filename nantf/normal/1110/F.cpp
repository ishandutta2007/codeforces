#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=500050;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct question{
	int l,r,id;
};
int n,q,el,head[maxn],to[maxn*2],nxt[maxn*2],w[maxn*2],sz[maxn],fa[maxn];
ll mx[maxn*4],add[maxn*4],dis[maxn],ans[maxn];
bool isl[maxn];
vector<question> qqq[maxn];
inline void addedge(int u,int v,int w_){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=w_;
}
inline void pushdown(int o){
	add[o<<1]+=add[o];
	add[o<<1|1]+=add[o];
	mx[o<<1]+=add[o];
	mx[o<<1|1]+=add[o];
	add[o]=0;
}
void build(int o,int l,int r){
	if(l==r) return void(mx[o]=isl[l]?dis[l]:1e18);
	int mid=(l+r)>>1;
	build(lson);build(rson);
	mx[o]=min(mx[o<<1],mx[o<<1|1]);
}
void update(int o,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr) return void((mx[o]+=v,add[o]+=v));
	int mid=(l+r)>>1;
	pushdown(o);
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
	mx[o]=min(mx[o<<1],mx[o<<1|1]);
}
ll query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return mx[o];
	int mid=(l+r)>>1;
	ll ans=1e18;
	pushdown(o);
	if(mid>=ql) ans=min(ans,query(lson,ql,qr));
	if(mid<qr) ans=min(ans,query(rson,ql,qr));
	return ans;
}
void dfs(int u){
	sz[u]=1;isl[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dis[v]=dis[u]+w[i];
		isl[u]=false;
		dfs(v);
		sz[u]+=sz[v];
	}
}
void dfs2(int u){
	FOR(i,0,(int)qqq[u].size()-1) ans[qqq[u][i].id]=query(1,1,n,qqq[u][i].l,qqq[u][i].r);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		update(1,1,n,1,n,w[i]);
		update(1,1,n,v,v+sz[v]-1,-2*w[i]);
		dfs2(v);
		update(1,1,n,1,n,-w[i]);
		update(1,1,n,v,v+sz[v]-1,2*w[i]);
	}
}
int main(){
	n=read();q=read();
	FOR(i,2,n){
		int u=read(),w=read();
		addedge(i,u,w);addedge(u,i,w);
	}
	FOR(i,1,q){
		int v=read(),l=read(),r=read();
		qqq[v].push_back((question){l,r,i});
	}
	dfs(1);
	build(1,1,n);
	dfs2(1);
	FOR(i,1,q) printf("%lld\n",ans[i]);
}