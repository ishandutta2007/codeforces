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
int dp[55][55][55][55],d[55],p[55],l[55],mod=1e9+7;
void add(int &x,int y){
	x=(x+y)%mod;
}
void solve(){
	int n;
	cin>>n;
	p[0]=1;
	FOR(i,1,n)p[i]=p[i-1]*i%mod;
	l[0]=1;
	l[1]=(mod+1)/2;
	FOR(i,2,n)l[i]=l[i-1]*l[1]%mod;
	FOR(i,1,n){
		cin>>d[i];
		d[i]-=i>1;
	}
//	FOR(i,1,n)cout<<d[i]<<' ';
//	cout<<'\n';
	int it=0;
	if(d[1]==2){
		it=3;
	}else it=4;
	if(d[2]==1)dp[2][it][1][0]=1;
	else dp[2][it][0][1]=1;
	rep(i,2,n){
		FOR(j,i+1,n){
			FOR(k1,0,i){
				FOR(k2,0,i)if(dp[i][j][k1][k2]){
					if(d[i+1]==1){
						add(dp[i+1][j][k1+1][k2],dp[i][j][k1][k2]);
						if(k1)add(dp[i+1][j][k1-1][k2],dp[i][j][k1][k2]*k1);
						if(k2)add(dp[i+1][j][k1+1][k2-1],dp[i][j][k1][k2]*k2);
					}else{
						add(dp[i+1][j][k1][k2+1],dp[i][j][k1][k2]);
						if(k1)add(dp[i+1][j][k1][k2],dp[i][j][k1][k2]*k1);
						if(k2)add(dp[i+1][j][k1+2][k2-1],dp[i][j][k1][k2]*k2);
						if(k1>1)add(dp[i+1][j][k1-2][k2],dp[i][j][k1][k2]*(k1*(k1-1)/2));
						if(k2>1)add(dp[i+1][j][k1+2][k2-2],dp[i][j][k1][k2]*(k2*(k2-1)/2));
						if(k1&&k2)add(dp[i+1][j][k1][k2-1],dp[i][j][k1][k2]*k1*k2);
					}
				}
			}
		}
		FOR(k1,0,i){
			FOR(k2,0,i)if(dp[i][i][k1][k2]&&i+k1+k2+k2<=n){
				if(d[i+1]==1)add(dp[i+1][i+k1+k2+k2][1][0],dp[i][i][k1][k2]*p[k1+k2+k2]%mod*l[k2]);
				else add(dp[i+1][i+k1+k2+k2][0][1],dp[i][i][k1][k2]*p[k1+k2+k2]%mod*l[k2]);
			}
		}
	}
	cout<<dp[n][n][0][0]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t=1;
	while(t--)solve();
	RE 0;
}