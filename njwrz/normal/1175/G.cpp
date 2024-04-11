//#pragma GCC optimize("Ofast", "inline", "-ffast-math")
//#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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
int maxi=2e4,n;ll dp[105][20005];
struct tree1{
	int root[1<<16];
	int cntnode;
	int ch[2][1<<22];
	P<ll,ll> ex[1<<22];
	void clear(){
		FOR(i,1,cntnode)ch[0][i]=ch[1][i]=0;
		cntnode=0;
		rep(i,1,1<<16)root[i]=0;
	}
	ll get(P<ll,ll> x,ll val){
		RE x.F*val+x.S;
	}
	void update(int &x,int l,int r,P<ll,ll> now){
		if(!x){
			x=++cntnode;
			ex[x]=now;
			RE;
		}
		int mid=(l+r)>>1;
		if(get(ex[x],mid)>get(now,mid)){
			swap(ex[x],now);
		}
		if(l!=r){
			if(now.F>ex[x].F)update(ch[0][x],l,mid,now);
			else update(ch[1][x],mid+1,r,now);
		}
	}
	ll get(int x,int l,int r,int it){
		if(!x)RE 1e18;
		ll re=get(ex[x],it);
		if(l==r)RE re;
		int mid=(l+r)>>1;
		if(mid>=it)gmin(re,get(ch[0][x],l,mid,it));
		else gmin(re,get(ch[1][x],mid+1,r,it));
		RE re;
	}
	void update(int x,int l,int r,int it,P<ll,ll> now){
		update(root[x],0,maxi,now);
		if(l==r)RE;
		int mid=(l+r)>>1;
		if(mid>=it)update(lc,l,mid,it,now);
		else update(rc,mid+1,r,it,now);
	}
	ll get(int x,int l,int r,int tl,int tr,ll val){
		if(l>tr||tl>r)RE 1e18;
		if(l>=tl&&r<=tr){
			RE get(root[x],0,maxi,val);
		}
		int mid=(l+r)>>1;
		RE min(get(lc,l,mid,tl,tr,val),get(rc,mid+1,r,tl,tr,val));
	}
}T1;
struct tree2{
	int root[1<<16];
	int cntnode;
	int ch[2][1<<22];
	P<ll,ll> ex[1<<22];
	void clear(){
		FOR(i,1,cntnode)ch[0][i]=ch[1][i]=0;
		cntnode=0;
		rep(i,1,1<<16)root[i]=0;
	}
	ll get(P<ll,ll> x,ll val){
		RE x.F*val+x.S;
	}
	void update(int &x,int l,int r,P<ll,ll> now){
		if(!x){
			x=++cntnode;
			ex[x]=now;
			RE;
		}
		int mid=(l+r)>>1;
		if(get(ex[x],mid)>get(now,mid)){
			swap(ex[x],now);
		}
		if(l!=r){
			if(now.F>ex[x].F)update(ch[0][x],l,mid,now);
			else update(ch[1][x],mid+1,r,now);
		}
	}
	ll get(int x,int l,int r,int it){
		if(!x)RE 1e18;
		ll re=get(ex[x],it);
		if(l==r)RE re;
		int mid=(l+r)>>1;
		if(mid>=it)gmin(re,get(ch[0][x],l,mid,it));
		else gmin(re,get(ch[1][x],mid+1,r,it));
		RE re;
	}
	void update(int x,int l,int r,int tl,int tr,P<ll,ll> now){
		if(tl>r||l>tr)RE;
		if(l>=tl&&r<=tr)RE update(root[x],0,maxi,now);
		int mid=(l+r)>>1;
		update(lc,l,mid,tl,tr,now);
		update(rc,mid+1,r,tl,tr,now);
	}
	ll get(int x,int l,int r,int it,ll val){
		ll re=get(root[x],0,maxi,val);
		if(l==r)RE re;
		int mid=(l+r)>>1;
		if(mid>=it)RE min(re,get(lc,l,mid,it,val));
		else RE min(re,get(rc,mid+1,r,it,val));
	}
}T2;
int a[20005],ls[20005],rs[20005];
void dfs(int x,int l,int r){
	ll t=T1.get(1,0,n,l,x-1,a[x]);
//	cout<<x<<' '<<l<<' '<<r<<' '<<t<<'\n';
	T2.update(1,0,n,x,r,MP(a[x],t));
	if(ls[x])dfs(ls[x],l,x-1);
	if(rs[x])dfs(rs[x],x,r);
}
signed main(){
//	freopen("in.txt","r",stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	V<int> v;
	FOR(i,1,n){
		while(!v.empty()&&a[v.back()]<=a[i])v.pop_back();
		if(!v.empty())rs[v.back()]=i;
		v.PB(i);
	}
	int rt=v[0];
	v.clear();
	for(int i=n;i>=1;i--){
		while(!v.empty()&&a[v.back()]<a[i])v.pop_back();
		if(!v.empty())ls[v.back()]=i;
		v.PB(i);
	}
	FOR(i,1,n)dp[0][i]=1e18;
	FOR(i,1,k){
		T1.clear();T2.clear();
		FOR(j,0,n)T1.update(1,0,n,j,MP(-j,dp[i-1][j]));
		dfs(rt,0,n);
		FOR(j,1,n)dp[i][j]=T2.get(1,0,n,j,j);
//		cout<<'\n';
	}
	cout<<dp[k][n];
	RE 0;
}