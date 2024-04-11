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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int n,a[200005],ans[200005],m;
V<int> g[200005];
struct SegmentTree{
	int maxi[1<<19],mini[1<<19],tag[1<<19];
	void pushdown(int x){
		maxi[rc]+=tag[x];
		maxi[lc]+=tag[x];
		tag[rc]+=tag[x];
		tag[lc]+=tag[x];
		mini[rc]+=tag[x];
		mini[lc]+=tag[x];
		tag[x]=0;
	}
	void update(int x,int L,int R,int l,int r,int add){
		if(L>r||l>R)RE ;
		if(l<=L&&r>=R){
			maxi[x]+=add;
			mini[x]+=add;
			tag[x]+=add;
			RE;
		}
		pushdown(x);
		int mid=(L+R)>>1;
		update(lc,L,mid,l,r,add);
		update(rc,mid+1,R,l,r,add);
		maxi[x]=max(maxi[lc],maxi[rc]);
		mini[x]=min(mini[lc],mini[rc]);
	}
	P<int,int> get(int x,int L,int R,int l,int r){
		if(L>r||l>R)RE MP(-1e9,1e9);
		if(l<=L&&r>=R){
			RE MP(maxi[x],mini[x]);
		}
		pushdown(x);
		int mid=(L+R)>>1;
		P<int,int> p1=get(lc,L,mid,l,r),p2=get(rc,mid+1,R,l,r);
		RE MP(max(p1.F,p2.F),min(p1.S,p2.S));
	}
}TL,TR;
void add(int x){
	TL.update(1,0,n+1,x,n+1,1);
	TR.update(1,0,n+1,0,x,1);
}
void era(int x){
	TL.update(1,0,n+1,x,n+1,-2);
	TR.update(1,0,n+1,0,x,-2);
}
P<int,int> p(P<int,int> x,P<int,int> y){
	RE MP(x.F-y.F,x.S-y.S);
}
int get(int x){
	P<int,int> pl=p(TL.get(1,0,n+1,x,x),TL.get(1,0,n+1,0,x-1)),pr=p(TR.get(1,0,n+1,x,x),TR.get(1,0,n+1,x+1,n+1));
	pl.F*=-1;pr.F*=-1;
	RE max((pl.F+pr.F-2)/2,(pl.S+pr.S-1)/2);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	V<int> v;
	FOR(i,1,n)cin>>a[i],v.PB(a[i]);
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	m=v.size();
	FOR(i,1,n)a[i]=lwb(ALL(v),a[i])-v.begin()+1,g[a[i]].PB(i);
	FOR(i,1,n)add(i);
	FOR(i,1,m){
		for(auto u:g[i])gmax(ans[u],get(u));
		for(auto u:g[i])era(u);
		for(auto u:g[i])gmax(ans[u],get(u));
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	RE 0;
}