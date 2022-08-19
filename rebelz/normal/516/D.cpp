#include<bits/stdc++.h>

#define y1 dmytxdy
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int lch,rch,val;
}t[10000005];

int n,q,tot,op,ncnt,ntot; ll dm;
int v[200005],nxt[200005],h[100005],f[100005][20],dfn[100005],rnk[100005],vs[100005],siz[100005];
ll dep[100005],c[200005],d[100005],p[100005],td[100005];
pll mx1[100005],mx2[100005];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

pll operator+(pll x,ll y){return mp(x.fi+y,x.se);}

void dfs1(int u){
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	mx1[u]=mp(0,u);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==f[u][0]) continue;
		f[v[p]][0]=u,dep[v[p]]=dep[u]+1,td[v[p]]=td[u]+c[p];
		dfs1(v[p]);
		if(mx1[v[p]]+c[p]>mx1[u]) mx2[u]=mx1[u],mx1[u]=mx1[v[p]]+c[p];
		else chkmax(mx2[u],mx1[v[p]]+c[p]);
	}
	if(chkmax(dm,mx1[u].fi+mx2[u].fi)) op=u;
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

ll dist(int x,int y){return td[x]+td[y]-(td[lca(x,y)]<<1);}

void dfs2(int u,int fa){
	dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs2(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

void build(int id,int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	build(t[id].lch=++ntot,l,mid);
	build(t[id].rch=++ntot,mid+1,r);
}

int change(int id,int l,int r,int x){
	int rt=++ntot,mid=(l+r)/2;
	t[rt]=t[id]; t[rt].val++;
	if(l==r) return rt;
	if(x<=mid) t[rt].lch=change(t[id].lch,l,mid,x);
	else t[rt].rch=change(t[id].rch,mid+1,r,x);
	return rt;
}

int query(int id1,int id2,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id2].val-t[id1].val;
	int mid=(l+r)/2;
	if(qr<=mid) return query(t[id1].lch,t[id2].lch,l,mid,ql,qr);
	else if(ql>mid) return query(t[id1].rch,t[id2].rch,mid+1,r,ql,qr);
	else return query(t[id1].lch,t[id2].lch,l,mid,ql,mid)+query(t[id1].rch,t[id2].rch,mid+1,r,mid+1,qr);
}

int main(){
	n=readint();
	ll x,y,z;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint(); z=readint();
		addedge(x,y,z);
	}
	dep[1]=1; dfs1(1);
	for(int i=1;i<=n;i++) p[i]=d[i]=max(dist(i,mx1[op].se),dist(i,mx2[op].se));
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++) d[i]=lower_bound(p+1,p+n+1,d[i])-p;
	int rt=0; ll mina=1ll<<60;
	for(int i=1;i<=n;i++) if(chkmin(mina,d[i])) rt=i;
	dfs2(rt,-1);
	build(vs[0]=0,1,n);
	for(int i=1;i<=n;i++) vs[i]=change(vs[i-1],1,n,d[rnk[i]]);
	q=readint();
	while(q--){
		x=readint();
		int ans=0;
		for(int i=1;i<=n;i++) chkmax(ans,query(vs[dfn[i]-1],vs[dfn[i]+siz[i]-1],1,n,1,upper_bound(p+1,p+n+1,p[d[i]]+x)-p-1));
		printf("%d\n",ans);
	}
	return 0;
}