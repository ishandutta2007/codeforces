#pragma GCC optimize("Ofast","inline","unroll-loops")
#include<bits/stdc++.h>
#define ll long long
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
int n,a[500005];
V<int> v[500005],g[500005];
P<int,int> mi[500005];
int s[500005],m;
int tag[1<<20],mx[1<<20];
int it[500005];
void update(int x){
	mx[x]=min(mx[lc],mx[rc]);
}
void build(int x,int l,int r){
	if(l==r){
		mx[x]=-(m-l+1);RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);build(rc,mid+1,r);
	update(x);
}
void pushdown(int x){
	tag[lc]+=tag[x];
	tag[rc]+=tag[x];
	mx[lc]+=tag[x];
	mx[rc]+=tag[x];
	tag[x]=0;
}
void update(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr){
		tag[x]+=val;mx[x]+=val;RE;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	if(mid>=tl)update(lc,l,mid,tl,tr,val);
	if(tr>=mid+1)update(rc,mid+1,r,tl,tr,val);
	update(x);
}
void dfs(int x,int y,int m1,int m2){
	if(a[x]<a[m1]){
		m2=m1;m1=x;
	}else if(a[x]<a[m2])m2=x;
	mi[x]=MP(m1,m2);
	v[m1].PB(x);
	for(auto u:g[x])if(u!=y)dfs(u,x,m1,m2);
}
int get(int x,int l,int r,int tl,int tr){
	if(l>tr||tl>r)RE 2e9;
	if(l>=tl&&r<=tr)RE mx[x];
	int mid=(l+r)>>1;
	pushdown(x);
	RE min(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
int now[500005];
bool check(int x,int val){
	for(auto u:v[x]){
		int t=min(a[mi[u].S],a[mi[u].F]+val);
		now[u]=upb(s+1,s+m+1,t)-s-1;
		if(it[u]<now[u])update(1,1,m,it[u]+1,now[u],1);
	}
	int re=mx[1]>=0;
	for(auto u:v[x]){
		if(it[u]<now[u])update(1,1,m,it[u]+1,now[u],-1);
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		g[x].PB(y);
		g[y].PB(x);
	}
	cin>>m;
	FOR(i,1,m)cin>>s[i];
	sort(s+1,s+m+1);
	a[0]=1e9;
	dfs(1,-1,0,0);
	build(1,1,m);
	FOR(i,1,n){
		it[i]=upb(s+1,s+m+1,a[mi[i].F])-s-1;
		if(it[i])update(1,1,m,1,it[i],1);
	}
	int mi=2e9;
	FOR(i,1,n)if(!v[i].empty()){
		if(it[i]&&get(1,1,m,1,it[i])<0)continue;
		int l=0,r=min(mi,(int)(1e9)),mid,ans=-1;
		if(!check(i,r))continue;
		while(r>=l){
			mid=(l+r)>>1;
			if(check(i,mid)){
				ans=mid;r=mid-1;
			}else l=mid+1;
		}
		if(ans!=-1)gmin(mi,ans);
	}
	if(mi==(int)(2e9)){
		cout<<-1;
	}else cout<<mi;
	RE 0;
}