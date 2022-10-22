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
char s[1000005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%s",s+1);
	int n=strlen(s+1);
	string ans;
	FOR(i,1,n/4){
		int t=n-i*2+1;
		if(s[i*2-1]==s[t]||s[i*2-1]==s[t+1]){
			ans+=s[i*2-1];
		}else ans+=s[i*2];
	}
	if(n%4>=2){
		string ts=ans;reverse(ALL(ts));
		ans+=s[n/2];
		ans+=ts;
	}else{
		string ts=ans;
		reverse(ALL(ts));
		ans+=ts;
	}
	cout<<ans;
	RE 0;
}