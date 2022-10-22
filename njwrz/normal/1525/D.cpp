//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//
#pragma GCC optimize("Ofast")
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
int dp[2505][5005];
int p[5005],it[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n;
	m=0;int cnt=0;
	FOR(i,1,n){
		int x;
		cin>>x;
		if(x){
			p[++m]=i;
		}else it[++cnt]=i;
	}
	FILL(dp,-1);
	dp[0][0]=0;
	rep(i,0,m){
		rep(j,0,cnt)if(dp[i][j]!=-1){
			if(dp[i][j+1]==-1){
				dp[i][j+1]=dp[i][j];
			}else gmin(dp[i][j+1],dp[i][j]);
			if(dp[i+1][j+1]==-1){
				dp[i+1][j+1]=dp[i][j]+abs(p[i+1]-it[j+1]);
			}else{
				gmin(dp[i+1][j+1],dp[i][j]+abs(p[i+1]-it[j+1]));
			}
		}
	}
	int ans=1e9;
	FOR(j,m,cnt){
		if(dp[m][j]!=-1)gmin(ans,dp[m][j]);
	}
	cout<<ans;
	RE 0;
}