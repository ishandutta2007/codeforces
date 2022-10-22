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
int n,k,mod=1e9+7;
int __pow(int x,int y){
	if(!y)RE 1;
	int t=__pow(x,y/2);
	t=t*t%mod;
	if(y&1)RE t*x%mod;
	else RE t;
}
int dp[205][405],p[205],f[405],ans[205],l[205][205],d[205][405];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	dp[0][0]=1;
	p[0]=1;f[0]=1;
	FOR(i,1,k+1){
		p[i]=__pow(i,mod-2);
		l[i][0]=1;
		FOR(j,1,k)l[i][j]=l[i][j-1]*p[i]%mod;
		p[i]=p[i]*p[i-1]%mod;
	}
	FOR(i,1,2*k)f[i]=f[i-1]*(n-i+1)%mod;
	FOR(i,n+1,2*k)f[i]=0;
	FOR(now,2,k+1){
		for(int cnt=1;cnt<=min(k/(now-1),2*k/now);cnt++)FOR(i,(now-1)*cnt,k){
			FOR(j,now*cnt,k*2){
				add(d[i][j],dp[i-(now-1)*cnt][j-now*cnt]*l[now][cnt]%mod*p[cnt]%mod);
			}
		}
		FOR(i,0,k){
			FOR(j,0,2*k)add(dp[i][j],d[i][j]),d[i][j]=0;
		}
	}
	ans[0]=1;
	FOR(i,1,k){
		FOR(j,1,k*2)add(ans[i],dp[i][j]*f[j]%mod);
		if(i>1)add(ans[i],ans[i-2]);
		cout<<ans[i]<<' ';
	}
	RE 0;
}