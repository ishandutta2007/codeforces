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

const int cys=1000000007;
int n,k,L,tx,ty;
int x[2005],y[2005],c[2005],px[2005],py[2005];
vector<pii> v[2005];
multiset<int> g[2005];

ll mod(ll x){return x>=cys?x-cys:x;}

namespace sgt{
	ll sum[4100],lazy[4100],mina[4100],maxa[4100];
	void update(int id){
		mina[id]=min(mina[id<<1],mina[id<<1|1]);
		maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
		sum[id]=mod(sum[id<<1]+sum[id<<1|1]);
	}
	void build(int id,int l,int r){
		lazy[id]=0;
		if(l==r) return (void)(maxa[id]=mina[id]=0,sum[id]=0);
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		update(id);
	}
	void addtag(int id,int l,int r,int c){
		if(mina[id]>=c) return;
		lazy[id]=c,sum[id]=1ll*(L-px[c])*(px[r]-px[l-1])%cys,mina[id]=maxa[id]=c;
	}
	void pushdown(int id,int l,int r){
		if(lazy[id]){
			int mid=(l+r)/2;
			addtag(id<<1,l,mid,lazy[id]),addtag(id<<1|1,mid+1,r,lazy[id]);
			lazy[id]=0;
		}
	}
	void change(int id,int l,int r,int ql,int qr,ll c){
		if(ql>qr) return;
		if(l==ql&&r==qr&&(mina[id]>=c||maxa[id]<=c)) return addtag(id,l,r,c);
		pushdown(id,l,r);
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
		else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
		update(id);
	}
}

int main(){
	n=readint(); k=readint(); L=readint();
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint(),c[i]=readint();
	for(int i=1;i<=n;i++) px[i]=x[i],py[i]=y[i];
	tx=n,px[++tx]=L;
	ty=n,py[++ty]=L;
	sort(px+1,px+tx+1);
	sort(py+1,py+ty+1);
	tx=unique(px+1,px+tx+1)-px-1;
	ty=unique(py+1,py+ty+1)-py-1;
	px[0]=py[0]=-1;
	for(int i=1;i<=n;i++){
		x[i]=lower_bound(px+1,px+tx+1,x[i])-px;
		y[i]=lower_bound(py+1,py+ty+1,y[i])-py;
	}
	for(int i=1;i<=n;i++) v[y[i]].pb(mp(x[i],c[i]));
	ll ans=0;
	for(int i=1;i<=ty;i++){
		sgt::build(1,1,tx+1);
		for(int j=1;j<=k;j++) g[j].clear();
		for(int j=i;j<=ty;j++) for(auto r:v[j]) g[r.se].insert(r.fi);
		for(int j=1;j<=k;j++){
			g[j].insert(tx);
			int lst=0;
			for(auto r:g[j]) sgt::change(1,1,tx,lst+1,r,r),lst=r;
			g[j].insert(0);
		}
		for(int j=ty;j>=i;j--){
			for(auto r:v[j]){
				auto it1=g[r.se].lower_bound(r.fi),it2=it1,it3=it1; it2--,it3++;
				sgt::change(1,1,tx,*it2+1,r.fi,*it3);
				g[r.se].erase(it1);
			}
			ans=(ans+sgt::sum[1]*(py[j]-py[j-1])%cys*(py[i]-py[i-1]))%cys;
		}
	}
	printf("%lld\n",ans);
	return 0;
}