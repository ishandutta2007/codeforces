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

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int lch,rch,val;
}t[10000005];

int n,ncnt;
int vs[200005],p[200005];
ll lf[100005],rg[100005];
pii a[100005];

void build(int id,int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	build(t[id].lch=++ncnt,l,mid);
	build(t[id].rch=++ncnt,mid+1,r);
}

int change(int id,int l,int r,int x){
	int rt=++ncnt;
	t[rt]=t[id]; t[rt].val++;
	if(l==r) return rt;
	int mid=(l+r)/2;
	if(x<=mid) t[rt].lch=change(t[id].lch,l,mid,x);
	else t[rt].rch=change(t[id].rch,mid+1,r,x);
	return rt;
}

ll query(int id1,int id2,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return t[id2].val-t[id1].val;
	int mid=(l+r)/2;
	if(qr<=mid) return query(t[id1].lch,t[id2].lch,l,mid,ql,qr);
	else if(ql>mid) return query(t[id1].rch,t[id2].rch,mid+1,r,ql,qr);
	else return query(t[id1].lch,t[id2].lch,l,mid,ql,mid)+query(t[id1].rch,t[id2].rch,mid+1,r,mid+1,qr);
}

ll ask(int x1,int x2,int y1,int y2){return query(vs[x1-1],vs[x2],1,n<<1,y1,y2);}
ll getl(int x,int y){if(x>y) swap(x,y); return ((ask(1,x,1,x)+ask(y,n<<1,y,n<<1)+ask(1,x,y,n<<1)+ask(y,n<<1,1,x))>>1)-1;}
ll getr(int x,int y){if(x>y) swap(x,y); return (ask(x,y,x,y)>>1)-1;}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=readint(),p[a[i].fi]=a[i].se,p[a[i].se]=a[i].fi;
	build(vs[0]=0,1,n<<1);
	for(int i=1;i<=(n<<1);i++) vs[i]=change(vs[i-1],1,n<<1,p[i]);
	for(int i=1;i<=n;i++) lf[i]=getl(a[i].fi,a[i].se),rg[i]=getr(a[i].fi,a[i].se);
	ll ans=1ll*n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++) ans-=lf[i]*rg[i];
	ll res=0;
	for(int i=1;i<=n;i++) res+=(n-lf[i]-rg[i]-1)*(lf[i]+rg[i]);
	res>>=1;
	printf("%lld\n",ans-res);
	return 0;
}