#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n;
int a[300005];
P<int,int> mini[1<<20];
int tag[1<<20];
void pushdown(int x){
	mini[lc].F+=tag[x];tag[lc]+=tag[x];
	mini[rc].F+=tag[x];tag[rc]+=tag[x];
	tag[x]=0;
}
P<int,int> merge(P<int,int> x,P<int,int> y){
	if(x.F==y.F)RE MP(x.F,x.S+y.S);else RE min(x,y);
}
void update(int x,int l,int r,int tl,int tr,int add){
	if(l>=tl&&r<=tr){
		mini[x].F+=add;tag[x]+=add;RE;
	}
	if(l>tr||tl>r)RE ;
	int mid=(l+r)>>1;
	pushdown(x);
	update(lc,l,mid,tl,tr,add);
	update(rc,mid+1,r,tl,tr,add);
	mini[x]=merge(mini[lc],mini[rc]);
}
P<int,int> get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr)RE mini[x];
	if(l>tr||tl>r)RE MP(1e9,0);
	int mid=(l+r)>>1;
	pushdown(x);
	RE merge(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
void build(int x,int l,int r){
	mini[x]=MP(l,1);
	if(l==r)RE ;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		int x,y;
		cin>>x>>y;
		a[x]=y;
	}
	V<P<int,int> > mi,mx;
	int ans=0;
	build(1,1,n);
	FOR(i,1,n){
		int now=i;
		while(!mi.empty()&&mi.back().S>a[i]){
			update(1,1,n,mi.back().F,now-1,mi.back().S);
			now=mi.back().F;
			mi.pop_back();
		}
		update(1,1,n,now,i,-a[i]);
		mi.PB(MP(now,a[i]));
		now=i;
		while(!mx.empty()&&mx.back().S<a[i]){
			update(1,1,n,mx.back().F,now-1,-mx.back().S);
			now=mx.back().F;
			mx.pop_back();
		}
		update(1,1,n,now,i,a[i]);
		mx.PB(MP(now,a[i]));
		P<int,int> p=get(1,1,n,1,i);
		if(p.F==i)ans+=p.S;
		p=get(1,1,n,1,1);
//		cout<<p.F<<' '<<p.S<<'\n';
	}
	cout<<ans;
	RE 0;
}