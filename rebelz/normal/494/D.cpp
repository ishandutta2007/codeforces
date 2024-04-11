#include<bits/stdc++.h>

#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll s,ms,lazy;
}t[300000];

const int cys=1000000007;
int n,m,tot,cnt;
int v[200005],nxt[200005],c[200005],h[100005],rnk[100005],dfn[100005],siz[100005],ans[100005],dep[100005];
vector<pii> q[100005];

int mod(int x){return x>=cys?x-cys:x;}

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

void update(int id){
	t[id].s=mod(t[id<<1].s+t[id<<1|1].s);
	t[id].ms=mod(t[id<<1].ms+t[id<<1|1].ms);
}

void build(int id,int l,int r){
	if(l==r){
		t[id].s=dep[rnk[l]],t[id].ms=1ll*dep[rnk[l]]*dep[rnk[l]]%cys;
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void pushdown(int id,int l,int r){
	if(t[id].lazy){
		int mid=(l+r)/2;
		t[id<<1].lazy=mod(t[id<<1].lazy+t[id].lazy),t[id<<1|1].lazy=mod(t[id<<1|1].lazy+t[id].lazy);
		t[id<<1].ms=mod(mod(t[id<<1].ms+1ll*(mid-l+1)*t[id].lazy%cys*t[id].lazy%cys)+2ll*t[id].lazy*t[id<<1].s%cys);
		t[id<<1|1].ms=mod(mod(t[id<<1|1].ms+1ll*(r-mid)*t[id].lazy%cys*t[id].lazy%cys)+2ll*t[id].lazy*t[id<<1|1].s%cys);
		t[id<<1].s=mod(t[id<<1].s+1ll*t[id].lazy*(mid-l+1)%cys),t[id<<1|1].s=mod(t[id<<1|1].s+1ll*t[id].lazy*(r-mid)%cys);
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr){
		t[id].lazy=mod(t[id].lazy+c);
		t[id].ms=mod(mod(t[id].ms+1ll*(r-l+1)*c%cys*c%cys)+2ll*c*t[id].s%cys);
		t[id].s=mod(t[id].s+1ll*c*(r-l+1)%cys);
		return;
	}
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}

int query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id].ms;
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return mod(query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr));
}

void dfs1(int u,int fa){
	dfn[u]=++cnt,rnk[cnt]=u,siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=mod(dep[u]+c[p]);
		dfs1(v[p],u);
		siz[u]+=siz[v[p]];
	}
}

void dfs2(int u,int fa){
	for(int i=0;i<q[u].size();i++) ans[q[u][i].se]=mod(mod(2*query(1,1,n,dfn[q[u][i].fi],dfn[q[u][i].fi]+siz[q[u][i].fi]-1))+cys-t[1].ms);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		change(1,1,n,1,n,c[p]);
		change(1,1,n,dfn[v[p]],dfn[v[p]]+siz[v[p]]-1,mod(2*(cys-c[p])));
		dfs2(v[p],u);
		change(1,1,n,1,n,cys-c[p]);
		change(1,1,n,dfn[v[p]],dfn[v[p]]+siz[v[p]]-1,mod(2*c[p]));
	}
}

int main(){
	n=readint();
	int x,y,z;
	for(int i=1;i<=n-1;i++){
		x=readint(); y=readint(); z=readint();
		addedge(x,y,z);
	}
	dfs1(1,-1);
	build(1,1,n);
	m=readint();
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		q[x].push_back(mp(y,i));
	}
	dfs2(1,-1);
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}