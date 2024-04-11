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
#define y1 yyyy1111
using namespace std;
int n,Q;
P<int,int> p[300005];
int ex(int x,int y){
	RE abs(p[x].F-p[y].F)*(p[x].S+p[y].S);
}
int ans[300005];
V<P<int,int> > q[300005];
int val[300005];
int get(int x){
	int re=5e18;
	while(x<=n){
		gmin(re,val[x]);
		x+=x&-x;
	}
	RE re;
}
void update(int x,int y){
	while(x){
		gmin(val[x],y);
		x-=x&-x;
	}
}
V<P<int,int> > v[300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>Q;
	FOR(i,1,n)cin>>p[i].F>>p[i].S,val[i]=5e18;
	V<int> st;
	FOR(i,1,n){
		while(!st.empty()&&p[st.back()].S>=p[i].S){
			v[i].PB(MP(st.back(),ex(st.back(),i)));st.pop_back();
		}
		if(!st.empty())v[i].PB(MP(st.back(),ex(st.back(),i)));
		st.PB(i);
	}
	FOR(i,1,Q){
		int l,r;
		cin>>l>>r;
		q[r].PB(MP(l,i));
	}
	FOR(i,1,n){
		for(auto u:v[i])update(u.F,u.S);
		for(auto u:q[i]){
			ans[u.S]=get(u.F);
		}
	}
	FOR(i,1,Q)cout<<ans[i]<<'\n';
	RE 0;
}