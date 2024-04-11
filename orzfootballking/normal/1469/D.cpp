/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
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
using namespace std;
V<int> v;
int n;
void dfs(int n){
	if(n<=2){
		RE ;
	}
	rep(i,2,n){
		if(i*i>=n){
			v.PB(i);
			dfs(i);
			break;
		}
	}
}
bool vis[200005];
void solve(){
	cin>>n;v.clear();
	dfs(n-1);
	reverse(ALL(v));
	v.PB(n-1);
	FOR(i,1,n)vis[i]=0;
	V<P<int,int> > ans;
	for(auto u:v)vis[u]=1;
	ans.PB(MP(n,n-1));
	rep(i,2,n){
		if(!vis[i])ans.PB(MP(i,i+1));
	}
	int lst=0;reverse(ALL(v));v.PB(n);
	for(auto u:v){
		if(lst)ans.PB(MP(lst,u));
		if(lst)ans.PB(MP(lst,u));
		lst=u;
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans){
		cout<<u.F<<' '<<u.S<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	RE 0;
}