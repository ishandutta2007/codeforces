#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot,dx,dy,nowmax;
int v[1000005],nxt[1000005],c[1000005],h[500005],x[500005],y[500005],k[500005];
pii max1[500005],max2[500005];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=z; nxt[tot]=h[y]; h[y]=tot;
}

struct seg{
	int ncnt;
	int dfn[500005],rnk[500005],siz[500005],col[500005],dep[500005],f[500005],maxa[1100000][2],rev[1100000];
	void dfs(int u,int fa){
		dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa) continue;
			dep[v[p]]=dep[u]+1,col[v[p]]=col[u]^c[p],f[v[p]]=u;
			dfs(v[p],u);
			siz[u]+=siz[v[p]];
		}
	}
	void build(int id,int l,int r){
		if(l==r) return (void)(maxa[id][col[rnk[l]]]=dep[rnk[l]]);
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		for(int i=0;i<2;i++) maxa[id][i]=max(maxa[id<<1][i],maxa[id<<1|1][i]);
	}
	void pushdown(int id){
		if(rev[id]){
			rev[id<<1]^=1,swap(maxa[id<<1][0],maxa[id<<1][1]);
			rev[id<<1|1]^=1,swap(maxa[id<<1|1][0],maxa[id<<1|1][1]);
			rev[id]=0;
		}
	}
	void change(int id,int l,int r,int ql,int qr){
		if(l==ql&&r==qr) return (void)(rev[id]^=1,swap(maxa[id][0],maxa[id][1]));
		pushdown(id);
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr);
		else change(id<<1,l,mid,ql,mid),change(id<<1|1,mid+1,r,mid+1,qr);
		for(int i=0;i<2;i++) maxa[id][i]=max(maxa[id<<1][i],maxa[id<<1|1][i]);
	}
}t[2];

void dfs1(int u,int fa){
	max1[u].se=max2[u].se=u;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		if(max1[v[p]].fi+1>max1[u].fi) max2[u]=max1[u],max1[u]=mp(max1[v[p]].fi+1,max1[v[p]].se);
		else if(max1[v[p]].fi+1>max2[u].fi) max2[u]=mp(max1[v[p]].fi+1,max1[v[p]].se);
	}
	if(chkmax(nowmax,max1[u].fi+max2[u].fi)) dx=max1[u].se,dy=max2[u].se;
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) x[i]=readint(),y[i]=readint(),k[i]=readint();
	for(int i=1;i<n;i++) addedge(x[i],y[i],k[i]);
	dfs1(1,-1);
	t[0].dfs(dx,-1);
	t[0].build(1,1,n);
	t[1].dfs(dy,-1);
	t[1].build(1,1,n);
	int id;
	m=readint();
	for(int i=1;i<=m;i++){
		id=readint();
		if(t[0].f[x[id]]==y[id]) t[0].change(1,1,n,t[0].dfn[x[id]],t[0].dfn[x[id]]+t[0].siz[x[id]]-1);
		else t[0].change(1,1,n,t[0].dfn[y[id]],t[0].dfn[y[id]]+t[0].siz[y[id]]-1);
		if(t[1].f[x[id]]==y[id]) t[1].change(1,1,n,t[1].dfn[x[id]],t[1].dfn[x[id]]+t[1].siz[x[id]]-1);
		else t[1].change(1,1,n,t[1].dfn[y[id]],t[1].dfn[y[id]]+t[1].siz[y[id]]-1);
		printf("%d\n",max(t[0].maxa[1][0],t[1].maxa[1][0]));
	}
	return 0;
}