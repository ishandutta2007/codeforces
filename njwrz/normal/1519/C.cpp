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
int ans[200005],it[200005],val[200005];
V<int> v[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)v[i].clear(),ans[i]=0;
	FOR(i,1,n)cin>>it[i];
	FOR(i,1,n){
		cin>>val[i];
		v[it[i]].PB(val[i]);
	}
	FOR(i,1,n){
		if(v[i].empty())continue;
		sort(ALL(v[i]),greater<int>());
		int cnt=0,sum=0,m=v[i].size();
		for(auto u:v[i]){
			sum+=u;cnt++;
//			cout<<sum<<'\n';
			for(int j=1;j*j<=cnt;j++){
				if(cnt%j==0){
					if(m-cnt<j)ans[j]+=sum;
					if(j*j!=cnt&&m-cnt<cnt/j)ans[cnt/j]+=sum;
				}
			}
		}
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}