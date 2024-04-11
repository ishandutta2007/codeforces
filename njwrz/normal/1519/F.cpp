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
int dp[6][5][6][262144],a[7],b[7];
int n,m,c[7][7];
int dfs(int x,int lft,int y,int mask){
	if(y==m)RE 1e18;
	if(x==n)RE 0;
	if(dp[x][lft][y][mask])RE dp[x][lft][y][mask];
	int &re=dp[x][lft][y][mask];
	re=1e18;
	int now=(mask>>(y*3))&7;
	FOR(i,0,min(lft,now)){
		gmin(re,dfs(x+(i==lft),i==lft?a[x+1]:(lft-i),i==lft?0:(y+1),mask-(1<<(y*3))*i)+(i?c[x][y]:0));
	}
//	cout<<x<<' '<<lft<<' '<<y<<' '<<mask<<' '<<re<<'\n';
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int st=0;
	rep(i,0,n)cin>>a[i];
	rep(i,0,m)cin>>b[i],st+=(1<<(3*i))*b[i];
	rep(i,0,n)rep(j,0,m)cin>>c[i][j];
	cout<<(dfs(0,a[0],0,st)>=1e17?-1:dfs(0,a[0],0,st));
	RE 0;
}