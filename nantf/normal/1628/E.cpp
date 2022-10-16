#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1222222,mod=998244353;
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,q,fa[maxn],el,head[maxn],to[maxn],nxt[maxn],w[maxn],dep[maxn],id[maxn],seq[maxn],m,st[20][maxn],lt[maxn],cov[maxn];
struct edge{
	int u,v,w;
	bool operator<(const edge &e)const{return w<e.w;}
}e[maxn];
inline int getfa(int x){
	return fa[x]?fa[x]=getfa(fa[x]):x;
}
inline void add(int u,int v){
//	printf("add(%d,%d)\n",u,v);
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u){
	seq[++m]=u;
	id[u]=m;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dep[v]=dep[u]+1;
		dfs(v);
		seq[++m]=u;
	}
}
inline int lca(int u,int v){
	u=id[u];v=id[v];
	if(u>v) swap(u,v);
	int k=lt[v-u+1];
	int x=st[k][u],y=st[k][v-(1<<k)+1];
	return dep[x]<dep[y]?x:y;
}
inline ll dist(int u,int v){
	return w[lca(u,v)];
}
struct wtf{
	int u,v;
	wtf(int uu=-1,int vv=-1):u(uu),v(vv){}
	wtf operator+(const wtf &w)const{
		wtf ans;
		if(~u && ~w.u) ans.u=id[u]<id[w.u]?u:w.u;
		else ans.u=u&w.u;
		if(~v && ~w.v) ans.v=id[v]>id[w.v]?v:w.v;
		else ans.v=v&w.v;
		return ans;
	}
}seg[maxn],init[maxn];
inline void pushup(int o){
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
inline void setcov(int o,int v){
	cov[o]=v;
	seg[o]=v?init[o]:wtf(-1,-1);
}
inline void pushdown(int o){
	if(~cov[o]){
		setcov(o<<1,cov[o]);
		setcov(o<<1|1,cov[o]);
		cov[o]=-1;
	}
}
void build(int o,int l,int r){
	cov[o]=-1;
	if(l==r) return init[o]=wtf(l,l),void();
	int mid=(l+r)>>1;
	build(lson);build(rson);
	init[o]=init[o<<1]+init[o<<1|1];
}
void update(int o,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr) return setcov(o,v);
	int mid=(l+r)>>1;
	pushdown(o);
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
	pushup(o);
}
int main(){
	n=read();q=read();
	FOR(i,1,n-1){
		int u=read(),v=read(),w=read();
		e[i]=(edge){u,v,w};
	}
	sort(e+1,e+n);
	int cnt=n;
	FOR(i,1,n-1){
		int u=e[i].u,v=e[i].v;
		int uf=getfa(u),vf=getfa(v);
		if(uf==vf) continue;
		w[++cnt]=e[i].w;
		add(cnt,uf);add(cnt,vf);
		fa[uf]=fa[vf]=cnt;
	}
	dfs(cnt);
	lt[0]=-1;
	FOR(i,1,m) lt[i]=lt[i>>1]+1;
	FOR(i,1,m) st[0][i]=seq[i];
	FOR(i,1,lt[m]) FOR(j,1,m-(1<<i)+1){
		int x=st[i-1][j],y=st[i-1][j+(1<<(i-1))];
		st[i][j]=dep[x]<dep[y]?x:y;
	}
	build(1,1,n);
	while(q--){
		int op=read();
		if(op==1){
			int l=read(),r=read();
			update(1,1,n,l,r,1);
		}
		if(op==2){
			int l=read(),r=read();
			update(1,1,n,l,r,0);
		}
		if(op==3){
			int x=read();
			int u=seg[1].u,v=seg[1].v;
//			printf("u=%d,v=%d\n",u,v);
			ll ans=-1;
			if(~u && u!=x) ans=max(ans,dist(x,u));
			if(~v && v!=x) ans=max(ans,dist(x,v));
			printf("%lld\n",ans);
		}
	}
}