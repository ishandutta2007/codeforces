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

int n;
int a[200005],sum[600000],cov[600000];
pii mina[600000][2];
vector<int> vec[200005];

void build(int id,int l,int r){
	mina[id][0]=mp(n+1,n+1);
	mina[id][1]=mp(n+1,0);
	if(l==r) return;
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
}

void addtag(int id,int l,int r,int c){
	mina[id][0]=mp(c,l);
	mina[id][1]=mp(c,-r);
	cov[id]=c;
}

void pushdown(int id,int l,int r){
	if(cov[id]){
		int mid=(l+r)/2;
		addtag(id<<1,l,mid,cov[id]);
		addtag(id<<1|1,mid+1,r,cov[id]);
		cov[id]=0;
	}
}

void change(int id,int l,int r,int x){
	sum[id]++;
	if(l==r) return (void)(mina[id][0]=mp(a[x],x),mina[id][1]=mp(a[x],-x));
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x);
	else change(id<<1|1,mid+1,r,x);
	mina[id][0]=min(mina[id<<1][0],mina[id<<1|1][0]);
	mina[id][1]=min(mina[id<<1][1],mina[id<<1|1][1]);
}

pii query(int id,int l,int r,int ql,int qr,int fl){
	if(l==ql&&r==qr) return mina[id][fl];
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr,fl);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr,fl);
	else return min(query(id<<1,l,mid,ql,mid,fl),query(id<<1|1,mid+1,r,mid+1,qr,fl));
}

void cover(int id,int l,int r,int ql,int qr,int c){
//	cout<<"cover "<<id<<' '<<ql<<' '<<qr<<' '<<c<<endl;
	if(l==ql&&r==qr) return addtag(id,l,r,c);
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) cover(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) cover(id<<1|1,mid+1,r,ql,qr,c);
	else cover(id<<1,l,mid,ql,mid,c),cover(id<<1|1,mid+1,r,mid+1,qr,c);
	mina[id][0]=min(mina[id<<1][0],mina[id<<1|1][0]);
	mina[id][1]=min(mina[id<<1][1],mina[id<<1|1][1]);
}

int getsum(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return sum[id];
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return getsum(id<<1,l,mid,ql,qr);
	else if(ql>mid) return getsum(id<<1|1,mid+1,r,ql,qr);
	else return getsum(id<<1,l,mid,ql,mid)+getsum(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) vec[a[i]].pb(i);
	build(1,1,n);
	ll ans=0;
	for(int i=n;i>=1;i--){
		if(!vec[i].size()) continue;
		int lf=vec[i][0],rg=vec[i].back();
		int pl=lf==1?0:-query(1,1,n,1,lf-1,1).se;
		int pr=rg==n?n+1:query(1,1,n,rg+1,n,0).se;
		for(auto r:vec[i]) change(1,1,n,r);
//		cout<<"test "<<i<<' '<<pl+1<<' '<<pr-1<<' '<<getsum(1,1,n,pl+1,pr-1)<<endl;
		ans+=getsum(1,1,n,pl+1,pr-1);
		cover(1,1,n,pl+1,pr-1,i);
	}
	printf("%lld\n",ans);
	return 0;
}