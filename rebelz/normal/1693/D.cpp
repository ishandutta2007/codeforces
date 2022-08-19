// xtqqwq
#include<bits/stdc++.h>

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

int n,ncnt;
int rmn[200005],lmx[200005],lch[6000000],rch[6000000],mina[6000000],val[200005],a[200005],lim[200005],vs[200005],p[200005];

void add(int x,int c){
	for(;x<=n;x+=(x&(-x))) chkmax(val[x],c);
}

int ask(int x){
	int ret=-(1<<30);
	for(;x;x-=(x&(-x))) chkmax(ret,val[x]);
	return ret;
}

int build(int l,int r){
	int id=++ncnt;
	lch[id]=rch[id]=0;
	if(l==r){
		mina[id]=n+1;
		return id;
	}
	int mid=(l+r)/2;
	lch[id]=build(l,mid);
	rch[id]=build(mid+1,r);
	mina[id]=min(mina[lch[id]],mina[rch[id]]);
	return id;
}

int change(int id,int l,int r,int x,int c){
	int rt=++ncnt;
	lch[rt]=lch[id],rch[rt]=rch[id],mina[rt]=min(mina[id],c);
	if(l==r) return rt;
	int mid=(l+r)/2;
	if(x<=mid) lch[rt]=change(lch[id],l,mid,x,c);
	else rch[rt]=change(rch[id],mid+1,r,x,c);
	return rt;
}

int query(int id,int l,int r,int ql,int qr,int x){
	if(mina[id]>x) return l-1;
	if(l==r) return l;
	int mid=(l+r)/2;
	if(qr<=mid) return query(lch[id],l,mid,ql,qr,x);
	else if(ql>mid) return query(rch[id],mid+1,r,ql,qr,x);
	else{
		int tmp=query(rch[id],mid+1,r,mid+1,qr,x);
		if(tmp<=mid) return query(lch[id],l,mid,ql,mid,x);
		else return tmp;
	}
}

void work(){
	for(int i=1;i<=n;i++) val[i]=-n-1;
	for(int i=n;i>=1;i--){
		rmn[i]=-ask(a[i]);
		add(a[i],-i);
	}
	for(int i=1;i<=n;i++) val[i]=0;
	for(int i=1;i<=n;i++){
		lmx[i]=ask(n-a[i]+1);
		add(n-a[i]+1,i);
	}
	ncnt=0;
	vs[0]=build(1,n);
	for(int i=1;i<=n;i++) vs[i]=change(vs[i-1],1,n,p[i],rmn[p[i]]);
	int now=1;
	for(int i=1;i<=n;i++){
		int pl=lmx[i];
		chkmax(now,query(vs[a[i]-1],1,n,1,pl-1,pl-1)+1);
		chkmax(lim[i],now);
	}
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),p[a[i]]=i;
	work();
	for(int i=1;i<=n;i++) a[i]=n-a[i]+1,p[a[i]]=i;
	work();
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=i-lim[i]+1;
	printf("%lld\n",ans);
	return 0;
}