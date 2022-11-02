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
V<int> dp[5005];
int n,a[5005],k;
V<int> v[5005];
int px[5005],py[5005];
void solve(V<int> &x,V<int> y){
	V<int> re;
	int len=max(x.size(),y.size());
	while(x.size()<len)x.PB(-1e18);
	while(y.size()<len)y.PB(-1e18);
	rep(i,0,len)re.PB(max(x[i],y[i]));
	px[len]=-1e18;
	for(int i=len-1;i>=0;i--){
		px[i]=max(px[i+1],x[i]);
	}
	py[len]=-1e18;
	for(int i=len-1;i>=0;i--){
		py[i]=max(py[i+1],y[i]);
	}
	rep(i,0,x.size()){
		int t=max(k-i,i);
		if(t<y.size()){
			gmax(re[i],x[i]+py[t]);
		}
	}
	rep(i,0,y.size()){
		int t=max(k-i,i);
		if(t<x.size()){
			gmax(re[i],y[i]+px[t]);
		}
	}
	x=re;
}
V<int> tob(V<int> v){
	V<int> re;
	re.PB(-1e18);
	for(auto u:v)re.PB(u);
	RE re;
}
void dfs(int x,int fa){
	dp[x].resize(1);
	dp[x][0]=a[x];
	for(auto u:v[x])if(u!=fa){
		dfs(u,x);
		solve(dp[x],tob(dp[u]));
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;k++;
	FOR(i,1,n)cin>>a[i];
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	int ans=0;
	for(auto u:dp[1])gmax(ans,u);
	cout<<ans;
	RE 0;
}