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
unordered_map<ll,int> mp;
int n,m;
int dp[32][200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool sw=0;
	if(n>m)swap(n,m),sw=1;
	int k;
	cin>>k;
	FOR(i,1,k){
		int x,y;
		cin>>x>>y;
		if(sw)swap(x,y);
		mp[1ll*x*m+y]=1;
	}
	dp[0][1]=1;
	rep(i,0,30){
		FOR(j,1,n)if(dp[i][j]){
			int to=j+dp[i][j];
			if(mp.count(1ll*j*m+dp[i][j])){
				to++;
			}
			gmax(dp[i+1][min(n,to)],dp[i][j]);
			gmax(dp[i+1][j],min(m,to));
		}
		if(dp[i+1][n]==m){
			cout<<i+1;RE 0;
		}
	}
	int ans=30;
	int now=dp[30][n];
	while(now<m){
		int to=n+now;
		if(mp.count(1ll*n*m+now))to++;
		now=to;
		ans++;
	}
	cout<<ans;
	RE 0;
}