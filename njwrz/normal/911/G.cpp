#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
int tag[1<<19][105];
int n,a[200005];
void build(int x,int l,int r){
	FOR(i,1,100)tag[x][i]=i;
	if(l==r)RE;
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r); 
}
int to[105];
void pd(int x,int y){
	FOR(i,1,100){
		to[i]=tag[x][tag[y][i]];
	}
	FOR(i,1,100)tag[y][i]=to[i];
}
void pushdown(int x){
	pd(x,lc);
	pd(x,rc);
	FOR(i,1,100)tag[x][i]=i;
}
void update(int x,int l,int r,int tl,int tr,int fr,int to){
	if(l>=tl&&r<=tr){
		FOR(i,1,100)if(tag[x][i]==fr)tag[x][i]=to;
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	pushdown(x);
	update(lc,l,mid,tl,tr,fr,to);
	update(rc,mid+1,r,tl,tr,fr,to);
}
void solve(int x,int l,int r){
	if(l==r){
		cout<<tag[x][a[l]]<<' ';RE;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	solve(lc,l,mid);
	solve(rc,mid+1,r);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int q;
	cin>>q;
	build(1,1,n);
	FOR(i,1,q){
		int l,r,x,y;
		cin>>l>>r>>x>>y;
		update(1,1,n,l,r,x,y);
	}
	solve(1,1,n);
	RE 0;
}