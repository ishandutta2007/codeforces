/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
using namespace std;
V<P<int,int> > v,q[1<<18]; 
map<P<int,int> ,int> mp;
bool ans[100005];
int fa[200005],n,siz[200005];
void update(int x,int tl,int tr,int l,int r,int U,int V){
	if(tl>=l&&tr<=r){
		q[x].PB(MP(U,V));RE;
	}
	if(tl>r||l>tr)RE ;
	int mid=(tl+tr)>>1;
	update(x<<1,tl,mid,l,r,U,V);
	update((x<<1)|1,mid+1,tr,l,r,U,V);
}
int get(int x){
	RE (x==fa[x])?x:get(fa[x]); 
}
void merge(int x,int y){
	x=get(x);
	y=get(y);
	if(x!=y){
		if(siz[x]>siz[y])swap(x,y);
		v.PB(MP(x,y));
		siz[y]+=siz[x];
		fa[x]=y;
	}
}
void solve(int x,int l,int r){
	int st=v.size();
	bool tag=1;
	for(auto u:q[x]){
		merge(u.F,u.S+n);
		merge(u.F+n,u.S);
		if(get(u.F)==get(u.F+n)||get(u.S)==get(u.S+n)){
			tag=0;break;
		}
	}
	if(tag){
		if(l==r){
			ans[l]=1;
		}else{
			int mid=(l+r)>>1;
			solve(x<<1,l,mid);
			solve((x<<1)|1,mid+1,r);
		}
	}
	while(v.size()>st){
		siz[v.back().S]-siz[v.back().F];
		fa[v.back().F]=v.back().F;
		v.pop_back();
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>n>>q;
	FOR(i,1,2*n)fa[i]=i,siz[i]=1;
	int x,y;
	FOR(i,1,q){
		cin>>x>>y;
		if(mp[MP(x,y)]){
			update(1,1,q,mp[MP(x,y)],i-1,x,y);
			mp[MP(x,y)]=0;
		}else mp[MP(x,y)]=i;
	}
	for(auto u:mp){
		if(u.S){
			update(1,1,q,u.S,q,u.F.F,u.F.S);
		}
	}
	solve(1,1,q);
	FOR(i,1,q){
		if(ans[i]){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
	RE 0;
}