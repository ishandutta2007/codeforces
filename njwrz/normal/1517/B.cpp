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
#define ll long long
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
P<int,int> p[10005];
int a[105][105];
bool cmp(P<int,int> x,P<int,int> y){
	RE a[x.F][x.S]<a[y.F][y.S];
} 
bool f[105][105];
int ans[105][105];
void solve(){
	int n,m;
	cin>>n>>m;
	FILL(f,0);FILL(ans,0);
	int cnt=0;
	FOR(i,1,n)FOR(j,1,m)cin>>a[i][j],p[++cnt]=MP(i,j);
	sort(p+1,p+n*m+1,cmp);
	FOR(i,1,m){
		ans[p[i].F][i]=a[p[i].F][p[i].S];f[p[i].F][p[i].S]=1;
	}
	FOR(i,1,n){
		int it=1;
		FOR(j,1,m)if(!ans[i][j]){
			while(f[i][it])it++;
			ans[i][j]=a[i][it];
			it++;
		}
	}
	FOR(i,1,n){
		FOR(j,1,m)cout<<ans[i][j]<<' ';
		cout<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}