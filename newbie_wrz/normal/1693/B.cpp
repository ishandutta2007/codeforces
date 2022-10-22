#include<bits/stdc++.h>
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
int ans;
V<int> v[200005];
P<int,int> p[200005];
int val[200005];
void dfs(int x){
	if(!v[x].size()){
		ans++;val[x]=p[x].S;RE;
	}
	int sum=0;
	for(auto u:v[x]){
		dfs(u);
		sum+=val[u];
	}
	if(p[x].F>sum){
		sum=p[x].S;
		ans++;
	}
	gmin(sum,p[x].S);
	val[x]=sum;
}
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)v[i].clear();
	FOR(i,2,n){
		int x;
		cin>>x;
		v[x].PB(i);
	}
	ans=0;
	FOR(i,1,n)cin>>p[i].F>>p[i].S;
	dfs(1);
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}