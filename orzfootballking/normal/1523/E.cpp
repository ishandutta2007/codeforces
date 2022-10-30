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
int f[100005],finv[100005],mod=1e9+7;
int POW(int x,int y){
	if(!y)RE 1;
	int t=POW(x,y/2);
	t=t*t%mod;
	if(y&1){
		RE t*x%mod;
	}else RE t;
} 
int C(int x,int y){
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
void solve(){
	int n,k;
	cin>>n>>k;
	int ans=0;
	for(int p=1;(p-1)*(k-1)+p<=n;p++){
		ans=(ans+C(n-(p-1)*(k-1),p)*POW(C(n,p),mod-2))%mod;
	}
	cout<<ans+1<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=1;finv[0]=1;
	FOR(i,1,100000)f[i]=f[i-1]*i%mod,finv[i]=POW(f[i],mod-2);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}