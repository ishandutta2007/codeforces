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
int it[400005],pos[400005],fir[400005];
P<int,int> p[200005],ans[200005]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>p[i].F>>p[i].S;
		it[p[i].F]=p[i].S;
		it[p[i].S]=p[i].F;
		fir[p[i].F]=1;
	}
	int maxi=1e9;
	int lst=1e9;
	FOR(i,1,n){
		if(it[i]<=n){
			cout<<-1;RE 0;
		}
		if(it[i]<maxi){
			maxi=it[i];
		}else{
			if(it[i]>lst){
				cout<<-1;RE 0;
			}
			lst=it[i];
		}
	}
	maxi=1e9;
	int ans=0,t=0,full=0;
	FOR(i,1,n){
		if(it[i]<maxi){
			maxi=it[i];
			t+=fir[i];
		}else t+=!fir[i];
		if(i-1==n+n-maxi){
//			cout<<t<<' '<<i<<'\n';
			ans+=min(i-full-t,t);
			full=i;t=0;
		}
	}
	cout<<ans;
	RE 0;
}