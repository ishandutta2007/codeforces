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

int n,q;
ll a[200005],mina[600000],maxa[600000],lazy[600000],sum[600000];

void build(int id,int l,int r){
	if(l==r) return (void)(mina[id]=maxa[id]=sum[id]=a[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
	mina[id]=min(mina[id<<1],mina[id<<1|1]);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}

void pushdown(int id,int l,int r){
	int mid=(l+r)/2;
	if(lazy[id]){
		mina[id<<1]=mina[id<<1|1]=maxa[id<<1]=maxa[id<<1|1]=lazy[id<<1]=lazy[id<<1|1]=lazy[id];
		sum[id<<1]=lazy[id]*(mid-l+1),sum[id<<1|1]=lazy[id]*(r-mid);
		lazy[id]=0;
	}
}

void change(int id,int l,int r,int ql,int qr,ll c){
	if(c<=mina[id]) return;
	if(l==ql&&r==qr&&c>=maxa[id]) return (void)(mina[id]=maxa[id]=lazy[id]=c,sum[id]=c*(r-l+1));
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
	mina[id]=min(mina[id<<1],mina[id<<1|1]);
	sum[id]=sum[id<<1]+sum[id<<1|1];
}

pll query(int id,int l,int r,int ql,int qr,ll c){
	if(c<mina[id]) return mp(c,0);
	if(l==ql&&r==qr&&c>=sum[id]) return mp(c-sum[id],r-l+1);
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr,c);
	else{
		pll lson=query(id<<1,l,mid,ql,mid,c),rson=query(id<<1|1,mid+1,r,mid+1,qr,lson.fi);
		return mp(rson.fi,lson.se+rson.se);
	}
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build(1,1,n);
	int opt,x,y;
	while(q--){
		opt=readint(); x=readint(); y=readint();
		if(opt==1) change(1,1,n,1,x,y);
		else printf("%lld\n",query(1,1,n,x,n,y).se);
	}
	return 0;
}