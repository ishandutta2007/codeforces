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

int n,q,ncnt;
int lch[6000005],rch[6000005],val[6000005],a[200005],vs[200005];

void build(int id,int l,int r){
	if(l==r) return;
	int mid=(l+r)/2;
	build(lch[id]=++ncnt,l,mid);
	build(rch[id]=++ncnt,mid+1,r);
}

int change(int id,int l,int r,int x){
	int rt=++ncnt;
	lch[rt]=lch[id],rch[rt]=rch[id],val[rt]=val[id]+1;
	if(l==r) return rt;
	int mid=(l+r)/2;
	if(x<=mid) lch[rt]=change(lch[id],l,mid,x);
	else rch[rt]=change(rch[id],mid+1,r,x);
	return rt;
}

int query(int id1,int id2,int l,int r,int ql,int qr){
	if(ql>qr) return 0;
	if(l==ql&&r==qr) return val[id2]-val[id1];
	int mid=(l+r)/2;
	if(qr<=mid) return query(lch[id1],lch[id2],l,mid,ql,qr);
	else if(ql>mid) return query(rch[id1],rch[id2],mid+1,r,ql,qr);
	else return query(lch[id1],lch[id2],l,mid,ql,mid)+query(rch[id1],rch[id2],mid+1,r,mid+1,qr);
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	build(vs[0]=0,1,n);
	for(int i=1;i<=n;i++) vs[i]=change(vs[i-1],1,n,a[i]);
	int x1,y1,x2,y2;
	while(q--){
		x1=readint(); y1=readint(); x2=readint(); y2=readint();
		ll ans=1ll*n*(n-1)/2;
		ans-=1ll*(x1-1)*(x1-2)/2+1ll*(n-x2)*(n-x2-1)/2;
		int num1=query(vs[0],vs[x1-1],1,n,1,y1-1),num2=query(vs[x2],vs[n],1,n,1,y1-1);
		ans-=1ll*(y1-1)*(y1-2)/2-1ll*num1*(num1-1)/2-1ll*num2*(num2-1)/2;
		num1=query(vs[0],vs[x1-1],1,n,y2+1,n),num2=query(vs[x2],vs[n],1,n,y2+1,n);
		ans-=1ll*(n-y2)*(n-y2-1)/2-1ll*num1*(num1-1)/2-1ll*num2*(num2-1)/2;
		printf("%lld\n",ans);
	}
	return 0;
}