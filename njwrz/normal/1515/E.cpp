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
int dp[405][405][2],C[405][405],f[405],t[405],inv[405],finv[405];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,mod;
	cin>>n>>mod;
	C[0][0]=1;
	FOR(i,1,n){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	f[0]=1;finv[1]=finv[1]=1;inv[1]=1;
	FOR(i,1,n)f[i]=f[i-1]*i%mod;
	FOR(i,2,n){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	FOR(i,1,n){
		FOR(j,0,i){
			t[i]=(t[i]+C[i-1][j])%mod;
		}
	}
	dp[0][0][1]=1;
	dp[1][1][0]=1;
	FOR(i,1,n){
		FOR(j,1,i){
			FOR(k,2,j){
				(dp[i][j][0]+=dp[i-k][j-k][1]*t[k]%mod*finv[k])%=mod;
			}
			for(int k=0;2*k+1<=i&&k<=j;k++){
				(dp[i][j][1]+=dp[i-2*k-1][j-k][0])%=mod;
			}
		}
	}
	int ans=0;
	FOR(i,1,n){
		ans=(ans+f[i]*dp[n-1][i-1][1]+f[i]*dp[n][i][0])%mod;
	}
	cout<<ans;
	RE 0;
}