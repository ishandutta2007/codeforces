#pragma GCC optimize("inline")
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
P<int,int> mini[1<<21];
int n,a[500005],N=1e6,tag[1<<21];
void update(int x){
	if(mini[lc].F!=mini[rc].F)mini[x]=min(mini[lc],mini[rc]);
	else mini[x]=MP(mini[lc].F,mini[lc].S+mini[rc].S);
	mini[x].F+=tag[x]; 
}
void build(int x,int l,int r){
	if(l==r){
		mini[x]=MP(1e9,1);RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	update(x);
}
void update(int x,int l,int r,int it,int val){
	if(l==r){
		mini[x]=MP(tag[x]+val,1);RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update(lc,l,mid,it,val);else update(rc,mid+1,r,it,val);
	update(x);
}
void update(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr){
		tag[x]+=val;mini[x].F+=val;RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	if(mid>=tl)update(lc,l,mid,tl,tr,val);
	if(mid+1<=tr)update(rc,mid+1,r,tl,tr,val);
	update(x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>n>>q;
	FOR(i,1,n)cin>>a[i];
	build(1,1,N);
	FOR(i,1,n)update(1,1,N,a[i],0);
	rep(i,1,n)if(a[i]<a[i+1])update(1,1,N,a[i],a[i+1]-1,1);
	FOR(i,1,q){
		int x,val;
		cin>>x>>val;
		if(x>1&&a[x-1]<a[x])update(1,1,N,a[x-1],a[x]-1,-1);
		if(x<n&&a[x]<a[x+1])update(1,1,N,a[x],a[x+1]-1,-1);
		update(1,1,N,a[x],1e9);
		a[x]=val;
		update(1,1,N,a[x],0);
		if(x>1&&a[x-1]<a[x])update(1,1,N,a[x-1],a[x]-1,1);
		if(x<n&&a[x]<a[x+1])update(1,1,N,a[x],a[x+1]-1,1);
		if(mini[1].F!=0){
			cout<<1<<'\n';
		}else cout<<mini[1].S<<'\n';
	}
	RE 0;
}