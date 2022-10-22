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
P<int,int> s[205],e[205];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	FOR(i,1,k)cin>>s[i].F>>s[i].S;
	FOR(i,1,k)cin>>e[i].F>>e[i].S;
	V<char> ans;
	rep(i,1,n)ans.PB('U');
	rep(i,1,m)ans.PB('L');
	FOR(i,1,n/2){
		rep(j,1,m)ans.PB('R');
		ans.PB('D');
		rep(j,1,m)ans.PB('L');
		ans.PB('D');
	}
	if(n&1){
		rep(j,1,m)ans.PB('R');
	}else ans.pop_back();
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u;
	RE 0;
}