#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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
int n,m,q;
map<P<int,int>,int> mp;
int f[1<<19],mx[1<<19],mi[1<<19];
set<int> s1[200005],s2[200005];
void up(int x){
	mx[x]=max(mx[lc],mx[rc]);
	mi[x]=min(mi[lc],mi[rc]);
	f[x]=f[lc]|f[rc];
	f[x]|=mi[lc]<=mx[rc];
}
void erase2(int x,int l,int r,int it,int val){
	if(l==r){
		s2[l].erase(val);
		if(s2[l].empty())mx[x]=0;
		else{
			auto iter=s2[l].end();
			iter--;
			mx[x]=*iter;
		}
		f[x]=mi[x]<=mx[x];
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)erase2(lc,l,mid,it,val);
	else erase2(rc,mid+1,r,it,val);
	up(x);
}
void erase1(int x,int l,int r,int it,int val){
	if(l==r){
		s1[l].erase(val);
		if(s1[l].empty())mi[x]=1e9;
		else{
			mi[x]=*s1[l].begin();
		}
		f[x]=mi[x]<=mx[x];
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)erase1(lc,l,mid,it,val);
	else erase1(rc,mid+1,r,it,val);
	up(x);
}
void update2(int x,int l,int r,int it,int val){
	if(l==r){
		s2[l].emplace(val);
		auto iter=s2[l].end();
		iter--;
		mx[x]=*iter;
		f[x]=mi[x]<=mx[x];
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update2(lc,l,mid,it,val);
	else update2(rc,mid+1,r,it,val);
	up(x);
}
void update1(int x,int l,int r,int it,int val){
	if(l==r){
		s1[l].emplace(val);
		mi[x]=*s1[l].begin();
		f[x]=mi[x]<=mx[x];
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update1(lc,l,mid,it,val);
	else update1(rc,mid+1,r,it,val);
	up(x);
}
void build(int x,int l,int r){
	mi[x]=1e9;
	if(l==r)RE;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r); 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	build(1,1,m);
	FOR(i,1,q){
		int x,y;
		cin>>x>>y;
		if(mp[MP(x,y)]){
			if(x&1){
				erase1(1,1,m,(y+1)>>1,(x+1)>>1);
			}else erase2(1,1,m,(y+1)>>1,(x+1)>>1);
			mp[MP(x,y)]=0;
		}else{
			if(x&1){
				update1(1,1,m,(y+1)>>1,(x+1)>>1);
			}else update2(1,1,m,(y+1)>>1,(x+1)>>1);
			mp[MP(x,y)]=1;
		}
		if(f[1]){
			cout<<"NO\n";
		}else cout<<"YES\n";
	}
	RE 0;
}