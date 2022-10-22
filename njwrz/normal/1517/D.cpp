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
//                       `=---='

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
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int dp[505][505][11],pr[505][505],pd[505][505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	FOR(i,1,n){
		rep(j,1,m)cin>>pr[i][j];
	}
	rep(i,1,n){
		FOR(j,1,m)cin>>pd[i][j];
	}
	if(k&1){
		FOR(i,1,n){
			FOR(j,1,m)cout<<-1<<' ';
			cout<<'\n';
		}
		RE 0;
	}
	k/=2;
	FOR(sk,1,k){
		FOR(i,1,n)FOR(j,1,m)dp[i][j][sk]=1e18;
		FOR(i,1,n){
			FOR(j,1,m){
				if(i<n)gmin(dp[i+1][j][sk],dp[i][j][sk-1]+pd[i][j]);
				if(i>1)gmin(dp[i-1][j][sk],dp[i][j][sk-1]+pd[i-1][j]);
				if(j<m)gmin(dp[i][j+1][sk],dp[i][j][sk-1]+pr[i][j]);
				if(j>1)gmin(dp[i][j-1][sk],dp[i][j][sk-1]+pr[i][j-1]);
			}
		}
	}
	FOR(i,1,n){
		FOR(j,1,m)cout<<dp[i][j][k]*2<<' ';
		cout<<'\n';
	}
	RE 0;
}