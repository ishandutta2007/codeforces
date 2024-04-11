#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define vi vector<int>
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
using namespace __gnu_pbds;
const int N=1e5+9;
gp_hash_table<int,int> mp[N];
map<vi,int> H;
set<int> S;
vi g[N];
int cnt;
int dp(int u,int f){
	if(mp[u][f])return mp[u][f];
	vi cur;
	for(auto v:g[u]){
		if(v==f)continue;
		cur.pb(dp(v,u));
	}
	sort(all(cur));
	if(!H[cur])H[cur]=++cnt;
	return mp[u][f]=H[cur];
}
int main(){
	int n;
	scanf("%d",&n); 
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i,1,n+1){
		if(g[i].size()<4){
			S.insert(dp(i,0));
		}
	}
	printf("%d\n",(int)S.size());
}