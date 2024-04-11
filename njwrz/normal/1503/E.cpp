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
const int mod=998244353;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int dp[2050][2050];
int val1[2050],val2[2050],n,m;
int solve(int t=0){
	FILL(val1,0);FILL(val2,0);
	int ans=0;
	rep(i,1,m){
		FOR(j,1,n)val1[j]=val2[j]=0;
		int sum=0;
		FOR(j,1,n){
			add(sum,dp[m-i][j]);
			val2[j]=sum*dp[m-i][n-j+1]%mod;
		}
		sum=0;
		for(int j=n;j>=1;j--){
			add(sum,dp[i][n-j+1]);
			val1[j]=sum*dp[i][j]%mod;
		}
		sum=0;
		FOR(j,1,n){
			add(ans,val1[j+t]*sum%mod);add(sum,val2[j]);
		}
	}
	RE ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	dp[0][1]=1;
	FOR(i,1,2030){
		int sum=0;
		FOR(j,1,2030){
			add(sum,dp[i-1][j]);dp[i][j]=sum;
		}
	}
	int ans=solve();
	swap(n,m);
	add(ans,solve(1));
	cout<<ans*2%mod;
	RE 0;
}