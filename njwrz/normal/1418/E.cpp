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
int n,m,d[200005],p[200005],mod=998244353,l[200005],r[200005];
int __pow(int x,int y){
	if(!y)RE 1;
	int t=__pow(x,y/2);
	if(y&1){
		RE t*t%mod*x%mod;
	} else RE t*t%mod;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>d[i];
	sort(d+1,d+n+1);
	FOR(i,1,n)p[i]=(d[i]+p[i-1])%mod;
	l[0]=1;
	FOR(i,1,n)l[i]=l[i-1]*i%mod; 
	r[n+1]=1;
	for(int i=n;i>=1;i--)r[i]=r[i+1]*i%mod;
	FOR(i,1,m){
		int a,b;
		cin>>a>>b;
		int it=lwb(d+1,d+n+1,b)-d-1;
		if(n-it<a){
			cout<<0<<'\n';continue;
		}
		int ans=0;
		if(it)ans=l[n-it]*(n-it-a+1)%mod*r[n-it+2]%mod*p[it]%mod;
		if(it<n){
			ans=(ans+l[n-it-1]*r[n-it+1]%mod*(n-it-a)%mod*(p[n]-p[it]))%mod;
		}
		cout<<(ans*__pow(l[n],mod-2)%mod+mod)%mod<<'\n';
	}
	RE 0;
}