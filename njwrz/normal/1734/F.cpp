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
int dp[65][2][2][2];//m 
void solve(){
	int n,m;
	FILL(dp,0);
	cin>>n>>m;
	int lim1=m-1;
	dp[0][0][0][0]=1;
	FOR(i,0,60)rep(val,0,2)rep(i1,0,2)rep(i2,0,2){
		int now=dp[i][val][i1][i2];
		if(!now)continue;
		rep(val1,0,2){
			int val2=i2+val1+((n>>i)&1);
			int to1=i1;
			if(val1<((lim1>>i)&1))to1=0;else if(val1>((lim1>>i)&1))to1=1;
			dp[i+1][val^val1^(val2&1)][to1][val2>=2]+=now;
		}
	}
	int ans=0;
	ans+=dp[61][1][0][0];
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