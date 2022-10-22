#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
const int B=5e5;
int n,a[500005];
struct seg2{
	int tag[1<<21],mi[1<<21],siz[1<<21];
	void build(int x,int l,int r){
		mi[x]=l;siz[x]=tag[x]=0;
		if(l==r)RE;
		int mid=(l+r)>>1;
		build(lc,l,mid);
		build(rc,mid+1,r);
	}
	void pd(int x,int y){
		tag[x]+=y;
		mi[x]+=y;
	}
	void pushdown(int x){
		pd(lc,tag[x]);
		pd(rc,tag[x]);
		tag[x]=0;
	}
	void update(int x,int l,int r,int tl,int tr,int p){
		if(l>=tl&&r<=tr){
			pd(x,p);RE;
		}
		if(l>tr||tl>r)RE;
		int mid=(l+r)>>1;
		pushdown(x);
		update(lc,l,mid,tl,tr,p);
		update(rc,mid+1,r,tl,tr,p);
		mi[x]=min(mi[lc],mi[rc]);
	}
	int get(int x,int l,int r,int tl,int tr){
		if(l>=tl&&r<=tr)RE mi[x];
		if(l>tr||tl>r)RE 1e18;
		int mid=(l+r)>>1;
		pushdown(x);
		RE min(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
	}
}T2;
struct seg1{
	int siz[1<<20];
	void update(int x,int l,int r,int it,int val){
		if(l==r){
			siz[x]++;RE;
		}
		int mid=(l+r)>>1;
		if(mid>=it)update(lc,l,mid,it,val);
		else update(rc,mid+1,r,it,val);
		siz[x]=siz[lc]+siz[rc];
	}
	int get(int x,int l,int r,int val){
		if(l==r)RE -B+l;
		int mid=(l+r)>>1;
		if(-val-siz[lc]<=mid-B){
			RE get(lc,l,mid,val);
		}else RE get(rc,mid+1,r,val+siz[lc]);
	}
}T1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	T2.build(1,0,B*2);
	FOR(i,1,n){
		if(a[i]<0){
			T1.update(1,0,B,a[i]+B,1);
		}
		T2.update(1,0,B*2,0,a[i]-1+B,1);
		int ans=1e18;
		int pos=T1.get(1,0,B,0);
		ans=T2.get(1,0,B*2,pos+B,B*2);
		cout<<ans-B<<'\n';
	}
	RE 0;
}