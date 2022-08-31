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

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,tot,ncnt; ll ans;
int siz[100005],dep[100005],son[100005],dfn[100005],rnk[100005],top[100005],f[100005],v[200005],nxt[200005],h[100005];
ll a[100005];

ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}
ll mod(ll x){return x>=cys?x-cys:x;}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	siz[u]=1;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dep[v[p]]=dep[u]+1,f[v[p]]=u;
		dfs1(v[p],u);
		if(siz[v[p]]>siz[son[u]]) son[u]=v[p];
		siz[u]+=siz[v[p]];
	}
}

void dfs2(int u,int fa){
	dfn[u]=++ncnt,rnk[ncnt]=u;
	if(son[u]){
		top[son[u]]=top[u];
		dfs2(son[u],u);
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa||v[p]==son[u]) continue;
		top[v[p]]=v[p];
		dfs2(v[p],u);
	}
}

struct node{
	ll g;
}t[300000];

void build(int id,int l,int r){
	if(l==r) return (void)(t[id].g=a[rnk[l]]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id].g=gcd(t[id<<1].g,t[id<<1|1].g);
}

void getc(int id,int l,int r,ll c){
	if(gcd(c,a[rnk[r]])==gcd(c,t[id].g)) return (void)(ans=mod(ans+1ll*(r-l+1)*(gcd(c,a[rnk[r]])%cys)%cys));
	int mid=(l+r)/2;
	getc(id<<1|1,mid+1,r,c);
	getc(id<<1,l,mid,gcd(c,t[id<<1|1].g));
}

ll query(int id,int l,int r,int ql,int qr,ll c){
	if(l==ql&&r==qr){
		getc(id,l,r,c);
		return gcd(c,t[id].g);
	}
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr,c);
	else return query(id<<1,l,mid,ql,mid,query(id<<1|1,mid+1,r,mid+1,qr,c));
}

void getans(int u){
	ll now=0;
//	cout<<"test "<<u<<' ';
	while(u){
		now=gcd(now,query(1,1,n,dfn[top[u]],dfn[u],now));
		u=f[top[u]];
	}
//	cout<<ans<<endl;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n-1;i++) addedge(readint(),readint());
	dep[1]=1; dfs1(1,-1);
	top[1]=1; dfs2(1,-1);
	build(1,1,n);
	for(int i=1;i<=n;i++) getans(i);
	cout<<ans<<endl;
	return 0;
}