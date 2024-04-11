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
int a[100005],n,dp[100005];
map<int,P<int,int> > mp;
void solve(){
	mp.clear();
	mp[0]=MP(0,0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int t=0;
	FOR(i,1,n){
		t^=a[i];
		dp[i]=dp[i-1]+1;
		if(mp.count(t)){
			gmin(dp[i],mp[t].S+(i-mp[t].F-1));
		}
		mp[t]=MP(i,dp[i]);
	}
	cout<<dp[n]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}