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
int n,a[505][505];
void solve(){
	cin>>n;
	ll ans=0;
	FOR(i,1,n+n)FOR(j,1,n+n)cin>>a[i][j];
	FOR(i,n+1,n+n)FOR(j,n+1,n+n)ans+=a[i][j];
	ans+=min({a[n+n][1],a[n+n][n],a[n+1][1],a[n+1][n],a[1][n+n],a[n][n+n],a[1][n+1],a[n][n+1]});
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