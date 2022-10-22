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
int dp[1005];
bool f[1005];
void solve(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	char c;
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c;
			f[j]=c=='.';
			dp[j]=1e9;
		}
		FOR(j,1,m){
			if(!f[j]){
				dp[j]=dp[j-1];continue;
			}
			if(j>1&&f[j-1]){
				gmin(dp[j],dp[j-2]+y);
			}
			gmin(dp[j],dp[j-1]+x);
		}
		ans+=dp[m];
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}