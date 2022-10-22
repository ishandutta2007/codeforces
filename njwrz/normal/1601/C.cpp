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
#define rc ((x<<1)^1)
using namespace std;
int tag[1<<21];
int n,m,a[1000005],b[1000005];
P<int,int> maxi[1<<21],p[1000005];
V<int> v[1000005];
int mx;
void build(int x,int l,int r){
	tag[x]=0;
	if(l==r){
		maxi[x]=MP(-l,l);
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	maxi[x]=max(maxi[lc],maxi[rc]);
}
void pushdown(int x){
	tag[lc]+=tag[x];
	tag[rc]+=tag[x];
	maxi[lc].F+=tag[x];
	maxi[rc].F+=tag[x];
	tag[x]=0;
}
void update(int x,int l,int r,int it){
	if(l>=it){
		tag[x]++;
		maxi[x].F++;
		RE;
	}
	if(r<it)RE;
	int mid=(l+r)>>1;
	pushdown(x);
	update(lc,l,mid,it);
	update(rc,mid+1,r,it);
	maxi[x]=max(maxi[lc],maxi[rc]); 
}
P<int,int> get(int x,int l,int r,int tl){
	if(l>=tl)RE maxi[x];
	if(r<tl)RE MP(-1e9,-1e9);
	int mid=(l+r)>>1;
	pushdown(x);
	RE max(get(lc,l,mid,tl),get(rc,mid+1,r,tl));
}
struct bit{
	int s[2000005];
	int get(int x){
		int re=0;
		while(x){
			re+=s[x];
			x-=x&-x;
		}
		RE re;
	}
	void update(int x){
		while(x<=mx){
			s[x]++;
			x+=x&-x;
		}
	}
}T;
void solve(){
	cin>>n>>m;
	V<int> vn;;
	FOR(i,0,n)v[i].clear();
	FOR(i,1,n)cin>>a[i],vn.PB(a[i]);
	FOR(i,1,m)cin>>b[i],vn.PB(b[i]);
	sort(ALL(vn));
	vn.erase(unique(ALL(vn)),vn.end());
	mx=vn.size();
	FOR(i,1,n)a[i]=lwb(ALL(vn),a[i])-vn.begin()+1,p[i]=MP(a[i],i);
	FOR(i,1,m)b[i]=lwb(ALL(vn),b[i])-vn.begin()+1;
	sort(b+1,b+m+1);
	int it=0,pl=1,tp=1;
	build(1,0,n);
	sort(p+1,p+n+1);
	FOR(i,1,m){
		while(pl<=n&&p[pl].F<=b[i]){
			update(1,0,n,p[pl].S);pl++;
		}
		while(tp<=n&&p[tp].F<b[i]){
			update(1,0,n,p[tp].S);tp++;
		}
		P<int,int> t=get(1,0,n,it);
		it=t.S;
		v[it].PB(i);
	}
	int ans=0;
	FOR(i,1,n)a[i]=mx-a[i]+1;
	FOR(i,1,m)b[i]=mx-b[i]+1;
	FOR(i,0,n){
		if(i){
			ans+=T.get(a[i]);
			T.update(a[i]+1);
		}
		for(auto u:v[i]){
			ans+=T.get(b[u]);
			T.update(b[u]+1);
		}
	}
	cout<<ans<<'\n';
	FOR(i,0,mx+1)T.s[i]=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}