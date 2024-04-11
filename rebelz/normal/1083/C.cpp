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

int n,m,q,tot;
int in[400005],a[400005][20],dep[200005],v[200005],nxt[200005],h[200005],lg2[400005],p[200005],pos[200005];
pii t[1100000];

void addedge(int x,int y){v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;}

void dfs(int u){
	in[u]=++m,a[m][0]=dep[u];
	for(int p=h[u];p;p=nxt[p]){
		dep[v[p]]=dep[u]+1;
		dfs(v[p]);
		a[++m][0]=dep[u];
	}
}

int lca(int x,int y){
	if(in[x]>in[y]) swap(x,y);
	int k=lg2[in[y]-in[x]+1];
	return min(a[in[x]][k],a[in[y]-(1<<k)+1][k]);
}

bool can(int x,int y,int t1,int t2){
	int dl=lca(x,y);
	if(dep[t1]<dl||(lca(x,t1)!=dep[t1]&&lca(y,t1)!=dep[t1])) return false;
	if(dep[t2]<dl||(lca(x,t2)!=dep[t2]&&lca(y,t2)!=dep[t2])) return false;
	return true;
}

pii operator+(pii x,pii y){
	if(x.fi<0||y.fi<0) return mp(-1,-1);
	if(x.fi==0) return y;
	if(y.fi==0) return x;
	if(can(x.fi,x.se,y.fi,y.se)) return x;
	else if(can(x.fi,y.fi,x.se,y.se)) return mp(x.fi,y.fi);
	else if(can(x.fi,y.se,x.se,y.fi)) return mp(x.fi,y.se);
	else if(can(x.se,y.fi,x.fi,y.se)) return mp(x.se,y.fi);
	else if(can(x.se,y.se,x.fi,y.fi)) return mp(x.se,y.se);
	else if(can(y.fi,y.se,x.fi,x.se)) return y;
	else return mp(-1,-1);
}

void build(int id,int l,int r){
	if(l==r) return (void)(t[id]=mp(pos[l],pos[l]));
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id]=t[id<<1]+t[id<<1|1];
}

void change(int id,int l,int r,int x,int c){
	if(l==r) return (void)(t[id]=mp(c,c));
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
	t[id]=t[id<<1]+t[id<<1|1];
}

int query(int id,int l,int r,pii x){
	if((x+t[id]).fi>0) return r+1;
	if(l==r) return l;
	int mid=(l+r)/2; pii tmp=x+t[id<<1];
	if(tmp.fi>0) return query(id<<1|1,mid+1,r,tmp);
	else return query(id<<1,l,mid,x);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) p[i]=readint()+1,pos[p[i]]=i;
	for(int i=2;i<=n;i++) addedge(readint(),i);
	dep[1]=1; dfs(1);
	for(int i=2;i<=m;i++) lg2[i]=lg2[i>>1]+1;
	for(int i=1;(1<<i)<=m;i++) for(int j=1;j+(1<<i)-1<=m;j++) a[j][i]=min(a[j][i-1],a[j+(1<<(i-1))][i-1]);
	q=readint();
	build(1,1,n);
	int opt,x,y;
	while(q--){
		opt=readint();
		if(opt==1){
			x=readint(); y=readint();
			change(1,1,n,p[x],pos[p[y]]);
			change(1,1,n,p[y],pos[p[x]]);
			swap(pos[p[x]],pos[p[y]]);
			swap(p[x],p[y]);
		}
		else printf("%d\n",query(1,1,n,mp(0,0))-1);
	}
	return 0;
}