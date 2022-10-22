#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
int n,m,Q,k;
P<int,int> ed[500005]; 
int fa[50000005],siz[50000005];
V<int> v[500005];
V<P<int,int> > q[500005],op[1<<20];
P<int,int> ch[5000005];
int len;
int col[500005];
int getfa(int x){
	RE (fa[x]==x)?x:getfa(fa[x]);
}
void merge(int x,int y){
	x=getfa(x);
	y=getfa(y);
	if(x==y)RE;
	if(siz[x]>siz[y])swap(x,y);
	ch[++len]=MP(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
}
int ans[500005];
#define get(x,y,z) (x+n*y-n+n*k*z)
void update(int x,int l,int r,int tl,int tr,P<int,int> oper){
	if(l>=tl&&r<=tr){
		op[x].PB(oper);RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,oper);
	update(rc,mid+1,r,tl,tr,oper);
}
void solve(int x,int l,int r){
	int tp=len;
	for(auto u:op[x]){
		merge(get(ed[u.F].F,u.S,0),get(ed[u.F].S,u.S,1));
		merge(get(ed[u.F].F,u.S,1),get(ed[u.F].S,u.S,0));
	}
	if(l==r){
		for(auto u:q[l]){
			if(getfa(get(ed[u.F].F,u.S,0))!=getfa(get(ed[u.F].S,u.S,0))){
				col[u.F]=u.S;ans[l]=1;
			}
			v[u.F].pop_back();
			if(!col[u.F])RE;
			if(v[u.F].empty())update(1,1,Q,l+1,Q,MP(u.F,col[u.F]));
			else update(1,1,Q,l+1,v[u.F].back()-1,MP(u.F,col[u.F]));
		}
		RE;
	}
	int mid=(l+r)>>1;
	solve(lc,l,mid);solve(rc,mid+1,r);
	for(int i=len;i>tp;i--){
		fa[ch[i].F]=ch[i].F;
		siz[ch[i].S]-=siz[ch[i].F];
	}
	len=tp;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k>>Q;
	FOR(i,1,2*k*n)fa[i]=i,siz[i]=1;
	FOR(i,1,m){
		cin>>ed[i].F>>ed[i].S;
	}
	FOR(i,1,Q){
		int x,to;
		cin>>x>>to;
		q[i].PB(MP(x,to));
		v[x].PB(i);
	}
	FOR(i,1,m)reverse(ALL(v[i]));
	solve(1,1,Q);
	FOR(i,1,2*k*n)assert(siz[i]==1);
	FOR(i,1,Q){
		if(ans[i])cout<<"YES\n";else cout<<"NO\n";
	}
	RE 0;
}