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
int k,cnt,d[505];
int p[555],n; 
int dp[505][505][15],ch[505][10],f[505][15];
void dfs(int x){
	bool ff=0;
	rep(tp,0,10)if(ch[x][tp]){
		d[ch[x][tp]]=d[x]+1;
		ff=1;
		dfs(ch[x][tp]);
	}
	FOR(i,0,d[x]){
		FOR(j,0,k)dp[x][i][j]=1e9;
		if(ff)dp[x][i][0]=0;
		else {
			if(i==0){
				dp[x][0][0]=0;
			}else dp[x][i][1]=0;
		}
		bool fir=1;
		rep(tp,0,10)if(ch[x][tp]){
			FOR(j,0,k)f[i][j]=1e9;
			FOR(j,(i>0),k){
				FOR(l,0,k-j+(i>0))gmin(f[i][j+l-(i>0&&!fir)],dp[x][i][l]+dp[ch[x][tp]][i][j]);
			}
			fir=0;
			FOR(j,0,k)dp[x][i][j]=f[i][j];
		}
		FOR(j,0,k){
			dp[x][i][j]+=(d[x]-i)*p[x];
		}
	}
	rep(i,0,d[x]){
		FOR(j,0,k){
			gmin(dp[x][i][j+(i>0)],dp[x][d[x]][j]);
//			cout<<dp[x][d[x]][j]<<' ';
		}
//		cout<<'\n';
	}
//	cout<<x<<'\n';
//	FOR(i,0,d[x]){
//		FOR(j,0,k){
//			cout<<dp[x][i][j]<<' ';
//		}
//		cout<<'\n';
//	}
//	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	cnt=1;
	FOR(i,1,n){
		string s;
		cin>>s;
		int it=1;
		for(auto u:s){
			if(!ch[it][u-'0']){
				ch[it][u-'0']=++cnt;
				it=cnt;
			}else it=ch[it][u-'0'];
		}
		int m;
		cin>>m;
		p[it]+=m;
	}
	dfs(1);
	int ans=1e9;
	FOR(i,0,k)gmin(ans,dp[1][0][i]);
	cout<<ans;
	RE 0;
}