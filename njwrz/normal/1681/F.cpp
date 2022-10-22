#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
int n;
V<P<int,int> > v[500005];
int siz[500005],L[500005],R[500005],cnt;
V<int> g[500005];
int dep[500005];
int col[500005];
int in(int x,int y){
	RE L[x]<=L[y]&&R[x]>=R[y];
}
int S[500005],ans;
void dfs(int x,int y){
	siz[x]=1;L[x]=++cnt;
	for(auto u:v[x])if(u.F!=y){
		dep[u.F]=dep[x]+1;col[u.F]=u.S;
		dfs(u.F,x);
		siz[x]+=siz[u.F];
	}
	R[x]=cnt;
	int t=0;
	S[x]=siz[x];
//	cout<<x<<' '<<S[x]<<'\n';
	while(!g[col[x]].empty()&&in(x,g[col[x]].back())){
		S[x]-=siz[g[col[x]].back()];
		t+=S[g[col[x]].back()];
		g[col[x]].pop_back();
	}
	ans+=S[x]*t;
	g[col[x]].PB(x);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,2,n){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
	}
	dfs(1,-1);
	FOR(i,1,n)if(!g[i].empty()){
		int res=0,tp=0;
		for(auto u:g[i])res+=S[u],tp+=siz[u];
		ans+=res*(n-tp);
	}
	cout<<ans;
	RE 0;
}