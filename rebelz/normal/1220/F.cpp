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

int n;
int a[200005],dep[200005];

namespace T1{
	pii mina[600000];
	void build(int id,int l,int r){
		if(l==r) return (void)(mina[id]=mp(a[l],l));
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		mina[id]=min(mina[id<<1],mina[id<<1|1]);
	}
	pii query(int id,int l,int r,int ql,int qr){
		if(ql>qr) return mp(1<<30,-1);
		if(l==ql&&r==qr) return mina[id];
		int mid=(l+r)/2;
		if(qr<=mid) return query(id<<1,l,mid,ql,qr);
		else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
		else return min(query(id<<1,l,mid,ql,mid),query(id<<1|1,mid+1,r,mid+1,qr));
	}
	pii findnxt(int id,int l,int r,int x,int c){
		if(l==r){
			if(mina[id].fi>c) return mp(-1,l+1);
			else return mina[id];
		}
		int mid=(l+r)/2;
		if(x<=mid-1){
			if(mina[id<<1].fi<c){
				pii lson=findnxt(id<<1,l,mid,x,c);
				if(lson.fi==-1) return findnxt(id<<1|1,mid+1,r,mid,c);
				else return lson;
			}
			else return findnxt(id<<1|1,mid+1,r,mid,c);
		}
		else return findnxt(id<<1|1,mid+1,r,x,c);
	}
	pii getnxt(int x,int c){
		if(T1::query(1,1,n,x+1,n).fi>c) return findnxt(1,1,n,0,c);
		else return findnxt(1,1,n,x,c);
	}
	pii findlst(int id,int l,int r,int x,int c){
//		cout<<"findlst "<<id<<' '<<l<<' '<<r<<' '<<x<<' '<<c<<endl;
		if(l==r){
			if(mina[id].fi>c) return mp(-1,l-1);
			else return mina[id];
		}
		int mid=(l+r)/2;
		if(x>mid+1){
			if(mina[id<<1|1].fi<c){
				pii rson=findlst(id<<1|1,mid+1,r,x,c);
				if(rson.fi==-1) return findlst(id<<1,l,mid,mid+1,c);
				else return rson;
			}
			else return findlst(id<<1,l,mid,mid+1,c);
		}
		else return findlst(id<<1,l,mid,x,c);
	}
	pii getlst(int x,int c){
		if(T1::query(1,1,n,1,x-1).fi>c) return findlst(1,1,n,n+1,c);
		else return findlst(1,1,n,x,c);
	}
}

namespace T2{
	struct node{
		int maxa,lazy;
	}t[600000];
	void build(int id,int l,int r){
		if(l==r) return (void)(t[id].maxa=dep[l]);
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		t[id].maxa=max(t[id<<1].maxa,t[id<<1|1].maxa);
	}
	void add(int id,int c){t[id].maxa+=c,t[id].lazy+=c;}
	void pushdown(int id){if(t[id].lazy) add(id<<1,t[id].lazy),add(id<<1|1,t[id].lazy),t[id].lazy=0;}
	void change(int id,int l,int r,int ql,int qr,int c){
		if(ql>qr) return;
		if(l==ql&&r==qr) return add(id,c);
		pushdown(id);
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
		else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
		t[id].maxa=max(t[id<<1].maxa,t[id<<1|1].maxa);
	}
	void update(int id,int l,int r,int x,int c){
		if(l==r) return (void)(t[id].maxa=c);
		pushdown(id);
		int mid=(l+r)/2;
		if(x<=mid) update(id<<1,l,mid,x,c);
		else update(id<<1|1,mid+1,r,x,c);
		t[id].maxa=max(t[id<<1].maxa,t[id<<1|1].maxa);
	}
	int getnum(int id,int l,int r,int x){
		if(l==r) return t[id].maxa;
		pushdown(id);
		int mid=(l+r)/2;
		if(x<=mid) return getnum(id<<1,l,mid,x);
		else return getnum(id<<1|1,mid+1,r,x);
	}
}

void gettree(int l,int r,int fa){
	int tmp=T1::query(1,1,n,l,r).se;
	dep[tmp]=dep[fa]+1;
	if(l!=tmp) gettree(l,tmp-1,tmp);
	if(r!=tmp) gettree(tmp+1,r,tmp);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	T1::build(1,1,n);
	gettree(1,n,0);
	T2::build(1,1,n);
	int ans=T2::t[1].maxa,opt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) continue;
		int lpl=T1::getnxt(i,a[i]).se,rpl=T1::getlst(i,a[i]).se;
//		cout<<"pl "<<lpl<<' '<<rpl<<endl;
		if(lpl<i) T2::change(1,1,n,i+1,n,-1),T2::change(1,1,n,1,lpl-1,-1);
		else T2::change(1,1,n,i+1,lpl-1,-1);
		if(rpl>i) T2::change(1,1,n,1,i-1,1),T2::change(1,1,n,rpl+1,n,1);
		else T2::change(1,1,n,rpl+1,i-1,1);
		T2::update(1,1,n,i,T2::getnum(1,1,n,rpl)+1);
//		cout<<"test "<<i<<endl;
//		for(int i=1;i<=n;i++) cout<<T2::getnum(1,1,n,i)<<' ';
//		cout<<endl;
		if(chkmin(ans,T2::t[1].maxa)) opt=i%n;
	}
	cout<<ans<<' '<<opt<<endl;
	return 0;
}