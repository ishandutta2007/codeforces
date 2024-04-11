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
int dp[2][105][105][105],t,C[105][105],mod=1e9+7; 
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,K;
	cin>>n>>m>>K;
	C[0][0]=1;
	FOR(i,1,100){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
//		if(i<=5){
//			FOR(j,1,i)cout<<C[i][j]<<' ';
//			cout<<'\n';
//		}
	}
	FOR(i,1,n){
		dp[0][i][i][1]=1;
	}
	int ans=0;
	FOR(_,2,m){
		t^=1;
		FILL(dp[t],0);
		FOR(i,1,n){
			FOR(j,1,n){
				FOR(k,1,K)if(dp[t^1][i][j][k]){
					FOR(cnt,i,n-j)if(k*C[cnt-1][i-1]<=K){
						add(dp[t][cnt-i][j+cnt][k*C[cnt-1][i-1]],dp[t^1][i][j][k]);
					}
				}
			}
		}
		FOR(i,1,n)FOR(j,1,K)ans=(ans+dp[t][0][i][j]*(m-_+1))%mod;
//		cout<<ans<<'\n';
	}
	cout<<ans;
	RE 0;
}