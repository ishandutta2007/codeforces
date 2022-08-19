#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int x,y,val;
	bool operator<(const node c)const{return val>c.val;}
}e[300005];

int n,m,q,cnt,ncnt,tot;
int p[200005],dfn[400005],rnk[400005],siz[400005],d[400005],fa[400005],f[400005][20],v[400005],nxt[400005],h[400005],opt[500005],a[500005];
pii maxa[600000];

int getf(int x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void build(int id,int l,int r){
	if(l==r) return (void)(maxa[id]=mp(p[rnk[l]],l));
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
}

void change(int id,int l,int r,int x){
	if(l==r) return (void)(maxa[id]=mp(0,l));
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x);
	else change(id<<1|1,mid+1,r,x);
	maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
}

pii query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return maxa[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return max(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
}

void dfs(int u){
	if(u<=n) dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
	else dfn[u]=ncnt+1;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		f[v[p]][0]=u;
		dfs(v[p]);
		siz[u]+=siz[v[p]];
	}
}

int jump(int x,int k){
	for(int i=19;i>=0;i--) if(d[f[x][i]]>=k) x=f[x][i];
	return x;
}

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=n;i++) p[i]=readint();
	for(int i=1;i<=m;i++) e[i].x=readint(),e[i].y=readint(),e[i].val=q+1;
	for(int i=1;i<=q;i++){
		opt[i]=readint(); a[i]=readint();
		if(opt[i]==2) e[a[i]].val=i;
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	cnt=n;
	for(int i=1;i<=m;i++){
		int fx=getf(e[i].x),fy=getf(e[i].y);
		if(fx==fy) continue;
		cnt++;
		fa[fx]=fa[fy]=fa[cnt]=cnt;
		addedge(cnt,fx),addedge(cnt,fy);
		d[cnt]=e[i].val;
	}
	for(int i=cnt;i>=1;i--) if(!dfn[i]) dfs(i);
	build(1,1,n);
	for(int i=1;i<=q;i++){
		if(opt[i]==1){
			int k=jump(a[i],i);	
			pii tmp=query(1,1,n,dfn[k],dfn[k]+siz[k]-1);
			printf("%d\n",tmp.fi);
			change(1,1,n,tmp.se);
		}
	}
	return 0;
}