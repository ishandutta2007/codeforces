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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
V<int> v[200005];
int n,p[200005],k,s[200005];
map<int,int> dp[200005];
int dfs(int x,int y){
	if(!y)RE 0;
	if(v[x].empty())RE s[x]*y;
	if(dp[x].count(y))RE dp[x][y];
	int len=v[x].size(),res=y%len;
	V<int> now;
	int sum=0;
	for(auto u:v[x]){
		int t=dfs(u,y/len);
		sum+=t;
		if(res)now.PB(dfs(u,y/len+1)-t);
	}
	if(res){
		sort(ALL(now));reverse(ALL(now));
	}
	rep(i,0,res)sum+=now[i];
	RE dp[x][y]=sum+s[x]*y;
}
void solve(){
	cin>>n>>k;
	FOR(i,1,n)v[i].clear(),dp[i].clear();
	FOR(i,2,n){
		cin>>p[i];v[p[i]].PB(i);
	}
	FOR(i,1,n)cin>>s[i];
	cout<<dfs(1,k)<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;while(T--)solve();
	RE 0;
}