// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,ans;
int a[500005],p[500005],now[500005];
vector<int> vec[500005];

namespace sgt1{
	int lv[1100000],rv[1100000],ls[1100000],rs[1100000];
	void build(int id,int l,int r){
		lv[id]=rv[id]=ls[id]=rs[id]=1;
		if(l==r) return;
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
	}
	void change(int id,int l,int r,int x,int c){
		if(l==r) return (void)(lv[id]=rv[id]=c);
		int mid=(l+r)/2;
		if(x<=mid) change(id<<1,l,mid,x,c);
		else change(id<<1|1,mid+1,r,x,c);
		lv[id]=lv[id<<1],rv[id]=rv[id<<1|1];
		if(ls[id<<1]==mid-l+1&&rv[id<<1]!=lv[id<<1|1]) ls[id]=ls[id<<1]+ls[id<<1|1];
		else ls[id]=ls[id<<1];
		if(rs[id<<1|1]==r-mid&&rv[id<<1]!=lv[id<<1|1]) rs[id]=rs[id<<1|1]+rs[id<<1];
		else rs[id]=rs[id<<1|1];
	}
	int getl(int id,int l,int r,int x){
		if(l==r) return l;
		int mid=(l+r)/2;
		if(x<=mid) return getl(id<<1,l,mid,x);
		else{
			int t=getl(id<<1|1,mid+1,r,x);
			if(t==mid+1&&rv[id<<1]!=lv[id<<1|1]) return mid-rs[id<<1]+1;
			else return t;
		}
	}
	int getr(int id,int l,int r,int x){
		if(l==r) return r;
		int mid=(l+r)/2;
		if(x<=mid){
			int t=getr(id<<1,l,mid,x);
			if(t==mid&&rv[id<<1]!=lv[id<<1|1]) return mid+ls[id<<1|1];
			else return t;
		}
		else return getr(id<<1|1,mid+1,r,x);
	}
}

namespace sgt2{
	int mina[1100000];
	void build(int id,int l,int r){
		mina[id]=n+1;
		if(l==r) return;
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
	}
	void change(int id,int l,int r,int ql,int qr,int c){
		if(l==ql&&r==qr) return (void)(chkmin(mina[id],c));
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
		else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	}
	int query(int id,int l,int r,int x,int c){
		chkmin(c,mina[id]);
		if(l==r) return c;
		int mid=(l+r)/2;
		if(x<=mid) return query(id<<1,l,mid,x,c);
		else return query(id<<1|1,mid+1,r,x,c);
	}
}

pii getans(int x){
	return mp(sgt1::getl(1,1,n,x),sgt1::getr(1,1,n,x));
}

void upd(pii tmp,int i){
	chkmax(ans,(tmp.se-tmp.fi)/2);
	if((tmp.se-tmp.fi+1)&1){
		if(!now[tmp.fi]) sgt2::change(1,1,n,tmp.fi,tmp.se,i);
	}
	else{
		if(!now[tmp.fi]) sgt2::change(1,1,n,tmp.fi,(tmp.se+tmp.fi-1)/2,i);
		else sgt2::change(1,1,n,(tmp.se+tmp.fi+1)/2,tmp.se,i);
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) p[i]=a[i]=readint();
	sort(p+1,p+n+1);
	m=unique(p+1,p+n+1)-p-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+m+1,a[i])-p;
	for(int i=1;i<=n;i++) vec[a[i]].pb(i),now[i]=1;
	sgt1::build(1,1,n);
	sgt2::build(1,1,n);
	for(int i=1;i<=m;i++){
		for(auto r:vec[i]){
			sgt1::change(1,1,n,r,0);
			now[r]=0;
		}
		for(auto r:vec[i]){
			if(r>1) upd(getans(r-1),i);
			upd(getans(r),i);
			if(r<n) upd(getans(r+1),i);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",p[sgt2::query(1,1,n,i,n+1)]);
	return 0;
}