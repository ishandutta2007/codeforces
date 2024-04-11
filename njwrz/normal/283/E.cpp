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
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
int n,k;
int a[100005];
P<int,int> p[100005];
V<int> in[100005],out[100005];
int sum[1<<18][2];
int tag[1<<18];
void build(int x,int l,int r){
	sum[x][0]=r-l+1;
	if(l==r)RE;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void pushdown(int x){
	if(tag[x]){
		tag[lc]^=1;
		tag[rc]^=1;
		swap(sum[lc][0],sum[lc][1]);
		swap(sum[rc][0],sum[rc][1]);
		tag[x]=0;
	}
}
void update(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		tag[x]^=1;
		swap(sum[x][0],sum[x][1]);
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	pushdown(x);
	update(lc,l,mid,tl,tr);
	update(rc,mid+1,r,tl,tr);
	sum[x][0]=sum[lc][0]+sum[rc][0];
	sum[x][1]=sum[lc][1]+sum[rc][1];
}
int get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		RE sum[x][0];
	}
	if(l>tr||tl>r)RE 0;
	int mid=(l+r)>>1;
	pushdown(x);
	RE get(lc,l,mid,tl,tr)+get(rc,mid+1,r,tl,tr);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	FOR(i,1,k){
		cin>>p[i].F>>p[i].S;
		p[i].F=lwb(a+1,a+n+1,p[i].F)-a;
		p[i].S=upb(a+1,a+n+1,p[i].S)-a-1;
		in[p[i].F].PB(p[i].S);
		out[p[i].S+1].PB(p[i].F);
	}
	sort(p+1,p+n+1);
	ll ans=1ll*n*(n-1)*(n-2)/6;
	build(1,1,n);
	FOR(i,1,n){
		for(auto u:in[i]){
			update(1,1,n,i,u);
		}
		for(auto u:out[i]){
			update(1,1,n,u,i-1);
		}
		int now=get(1,1,n,1,i-1)+(n-i)-get(1,1,n,i+1,n);
		ans-=1ll*now*(now-1)/2;
	}
	cout<<ans;
	RE 0;
}