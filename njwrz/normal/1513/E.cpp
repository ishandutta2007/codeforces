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
int inv[100005],f[100005],finv[100005],mod=1e9+7,a[100005]; 
int C(int x,int y){
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	f[0]=finv[0]=1;
	inv[1]=f[1]=finv[1]=1;
	FOR(i,2,n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-(mod/i)*inv[mod%i]%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	int sum=0;
	FOR(i,1,n)cin>>a[i],sum+=a[i];
	if(sum%n!=0){
		cout<<0;RE 0;
	}
	sum/=n;
	int c1=0,c2=0;
	FOR(i,1,n)c1+=a[i]<sum,c2+=a[i]>sum;
	if(c1==0){
		cout<<1;RE 0;
	}
	sort(a+1,a+n+1);
	int t=C(n,c1+c2)*f[c1]%mod*f[c2]%mod*f[n-c1-c2]%mod,cnt=0;
	if(c1==1||c2==1)t=f[n]*inv[2]%mod;
	FOR(i,1,n){
		if(a[i]!=a[i-1]){
			t=t*finv[cnt]%mod;
			cnt=1;
		}else cnt++;
	}
	t=t*finv[cnt]%mod;
	cout<<t*2%mod<<'\n';
	RE 0;
}