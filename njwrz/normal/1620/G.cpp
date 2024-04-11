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
int cnt[23][26],mod=998244353;
int p[26];
int dp[1<<23];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	rep(i,0,n){
		string s;
		cin>>s;
		for(auto u:s)cnt[i][u-'a']++;
	}
	rep(mask,1,1<<n){
		rep(i,0,26)p[i]=1e9;
		rep(i,0,n)if(mask&(1<<i)){
			rep(j,0,26)gmin(p[j],cnt[i][j]);
		}
		dp[mask]=1;
		rep(i,0,26){
			dp[mask]=dp[mask]*(p[i]+1)%mod;
		}
	}
	for(int i=0;i<n;i++)rep(mask,0,1<<n)if(mask&(1<<i)){
		add(dp[mask],mod-dp[mask-(1<<i)]);
	}
	int ans=0;
	rep(mask,1,1<<n){
		int k=__builtin_popcount(mask);
		int sum=0;
		rep(i,0,n)if(mask&(1<<i)){
			sum=sum+k*(i+1);
		}
		if(k&1)ans^=(sum*dp[mask]);
		else ans^=(sum*(mod-dp[mask]));
	}
	cout<<ans;
	RE 0;
}