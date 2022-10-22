#pragma GCC optimize("Ofast")
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
using namespace std;
V<int> v[100005];
V<P<int,int> > vis[100005]; 
int fa[100005],n,ans,mod=1e9+7,a[100005],de[100005];
int gcd(int a,int b){
	if(!b)RE a;
	else RE gcd(b,a%b);
}
void dfs(int p){
	if(p==1)vis[p].PB(MP(0,a[1])),ans=a[1];
	else{
		vis[p].PB(MP(0,gcd(vis[fa[p]][0].S,a[p])));
		P<int,int> u;int t;
		for(int i=1;i<vis[fa[p]].size();i++){
			u=vis[fa[p]][i];
			t=gcd(a[p],u.S);
			if(t==vis[p].back().S)continue;
			ans=(ans+(u.F-vis[p].back().F)*vis[p].back().S)%mod;
			vis[p].PB(MP(u.F,t));
		}
		if(a[p]==vis[p].back().S){
			ans=(ans+(de[p]-vis[p].back().F+1)*a[p])%mod;
		}else{
			ans=(ans+(de[p]-vis[p].back().F)*vis[p].back().S)%mod;
			ans=(ans+a[p])%mod;
			vis[p].PB(MP(de[p],a[p]));
		}
	}
	for(auto nxt:v[p]){
		if(nxt==fa[p])continue;
		fa[nxt]=p;
		de[nxt]=de[p]+1;
		dfs(nxt);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1);
	cout<<ans;
	RE 0;
}