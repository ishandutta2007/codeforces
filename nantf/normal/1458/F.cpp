#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,el,head[maxn],to[maxn],nxt[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
namespace circ{
	int fa[maxn],son[maxn],sz[maxn],dep[maxn],top[maxn],dfn[maxn],id[maxn],cnt;
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
		dfn[u]=++cnt;
		id[cnt]=u;
		if(son[u]) dfs2(son[u],topf);
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(v==fa[u] || v==son[u]) continue;
			dfs2(v,v);
		}
	}
	inline int lca(int u,int v){
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			u=fa[top[u]];
		}
		return dep[u]<dep[v]?u:v;
	}
	inline int find(int u,int k){
		while(true){
			int d=dep[u]-dep[top[u]];
			if(d>=k) return id[dfn[u]-k];
			k-=d+1;u=fa[top[u]];
		}
	}
	struct circ{
		int u,r;
		bool check(const circ &c)const{
			return dep[u]+dep[c.u]-2*dep[lca(u,c.u)]<=r-c.r;
		}
		const circ operator+(const circ &c)const{
			int l=lca(u,c.u),dis=dep[u]+dep[c.u]-2*dep[l];
			if(dis<=r-c.r) return *this;
			if(dis<=c.r-r) return c;
			int d=(dis+r+c.r)/2,v=d-r<=dep[u]-dep[l]?find(u,d-r):find(c.u,d-c.r);
			return (circ){v,d};
		}
	};
}
namespace ctr{
	int tot,rt,sz[maxn],son[maxn],fa[maxn],dep[maxn],d[22][maxn],c1[maxn],c2[maxn];
	ll s1[maxn],s2[maxn];
	bool vis[maxn];
	void getrt(int u,int f){
		sz[u]=1;son[u]=0;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(v==f || vis[v]) continue;
			getrt(v,u);
			sz[u]+=sz[v];
			son[u]=max(son[u],sz[v]);
		}
		son[u]=max(son[u],tot-sz[u]);
		if(!rt || son[u]<son[rt]) rt=u;
	}
	void getdis(int u,int f,int dd){
		if(f) d[dd][u]=d[dd][f]+1;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(v==f || vis[v]) continue;
			getdis(v,u,dd);
		}
	}
	void getall(int u){
		vis[u]=true;
		getdis(u,0,dep[u]);
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(vis[v]) continue;
			rt=0;
			tot=sz[v];
			getrt(v,u);
			fa[rt]=u;
			dep[rt]=dep[u]+1;
			getall(rt);
		}
	}
	void init(){
		tot=2*n-1;
		getrt(1,0);
		getall(rt);
	}
	void update(int u,int w){
		int v=u;
		while(v){
			s1[v]+=d[dep[v]][u]*w;c1[v]+=w;
			if(dep[v]) s2[v]+=d[dep[v]-1][u]*w,c2[v]+=w;
			v=fa[v];
		}
	}
	ll query(int u){
		ll ans=0;
		int v=u;
		while(v){
			ans+=s1[v]+1ll*d[dep[v]][u]*c1[v];
			if(dep[v]) ans-=s2[v]+1ll*d[dep[v]-1][u]*c2[v];
			v=fa[v];
		}
		return ans;
	}
}
circ::circ c[maxn];
ll ans,pre[maxn];
void solve(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	c[mid+1]=(circ::circ){mid+1,pre[mid]=pre[mid+1]=0};
	FOR(i,mid+2,r) c[i]=c[i-1]+(circ::circ){i,0},pre[i]=pre[i-1]+c[i].r;
	circ::circ cc=(circ::circ){mid,0};
	int x=mid+1,y=mid+1;
	ROF(i,mid,l){
		if(i!=mid) cc=cc+(circ::circ){i,0};
		while(x<=r && cc.check(c[x]) && !c[x].check(cc)) ctr::update(c[x++].u,-1);
		while(y<=r && !c[y].check(cc)) ctr::update(c[y++].u,1);
		assert(x<=y);
		ans+=1ll*(x-mid-1)*cc.r;
		ans+=pre[r]-pre[y-1];
		ans+=(ctr::query(cc.u)+1ll*(y-x)*cc.r+pre[y-1]-pre[x-1])/2;
	}
	while(x<y) ctr::update(c[x++].u,-1);
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,n+i);add(n+i,u);
		add(v,n+i);add(n+i,v);
	}
	circ::dfs1(1,0);
	circ::dfs2(1,1);
	ctr::init();
	solve(1,n);
	printf("%lld\n",ans);
}