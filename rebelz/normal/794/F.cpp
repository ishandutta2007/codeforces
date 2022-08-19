#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll s[15],be[15];
}t[300000];

int n,q;
ll a[100005],b[100005][15];
ll tmp[15];

void update(int id){for(int i=0;i<10;i++) t[id].s[i]=t[id<<1].s[i]+t[id<<1|1].s[i];}

void build(int id,int l,int r){
	for(int i=0;i<10;i++) t[id].be[i]=i;
	if(l==r){
		for(int i=0;i<10;i++) t[id].s[i]=b[l][i];
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void pushdown(int id){
	for(int i=0;i<10;i++) tmp[i]=t[id<<1].s[i];
	for(int i=0;i<10;i++) if(t[id].be[i]!=i) t[id<<1].s[t[id].be[i]]+=tmp[i],t[id<<1].s[i]-=tmp[i];
	for(int i=0;i<10;i++) t[id<<1].be[i]=t[id].be[t[id<<1].be[i]];
	for(int i=0;i<10;i++) tmp[i]=t[id<<1|1].s[i];
	for(int i=0;i<10;i++) if(t[id].be[i]!=i) t[id<<1|1].s[t[id].be[i]]+=tmp[i],t[id<<1|1].s[i]-=tmp[i];
	for(int i=0;i<10;i++) t[id<<1|1].be[i]=t[id].be[t[id<<1|1].be[i]];
	for(int i=0;i<10;i++) t[id].be[i]=i;
}

void change(int id,int l,int r,int ql,int qr,int x,int y){
	if(x==y) return;
	if(l==ql&&r==qr){
		t[id].s[y]+=t[id].s[x],t[id].s[x]=0;
		for(int i=0;i<10;i++) if(t[id].be[i]==x) t[id].be[i]=y;
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,x,y);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,x,y);
	else change(id<<1,l,mid,ql,mid,x,y),change(id<<1|1,mid+1,r,mid+1,qr,x,y);
	update(id);
}

ll query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr){
		ll res=0;
		for(int i=0;i<10;i++) res+=t[id].s[i]*i;
		return res;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	ll nw;
	for(int i=1;i<=n;i++){
		nw=1;
		while(a[i]){
			b[i][a[i]%10]+=nw;
			a[i]/=10,nw*=10;
		}
	}
	build(1,1,n);
	ll opt,x,y,z;
	while(q--){
		opt=readint(); x=readint(); y=readint();
		if(opt==1){
			z=readint();
			change(1,1,n,x,y,z,readint());
		}
		else printf("%lld\n",query(1,1,n,x,y));
	}
	return 0;
}