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
bool ans[105][105];
V<int> v;
bool cmp(int x,int y){
	int t=0;
	cout<<1<<' '<<x<<' '<<y<<'\n';
	cin>>t;
	RE t;
}
int n;
bool check(int fr,int to){
	cout<<2<<' '<<v[fr]<<' '<<to+1<<' ';
	FOR(i,0,to)cout<<v[i]<<' ';
	cout<<'\n';
	int t;
	cin>>t;
	RE t;
}
void solve(){
	cin>>n;v.clear();
	rep(i,0,n)v.PB(i); 
	srand(time(0)); 
	stable_sort(ALL(v),cmp);
	FILL(ans,0);
	int l=n-2;
	for(int i=n-1;i>=0;i--){
		if(l==i){
			FOR(j,0,i)rep(k,i+1,n)ans[v[k]][v[j]]=1;
			l--;
		}
		while(l>=0&&check(i,l))l--;
	}
	cout<<3<<'\n';
	rep(i,0,n){
		rep(j,0,n)cout<<(ans[i][j]^1);
		cout<<'\n';
	}
	cin>>n;
} 
signed main(){
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}