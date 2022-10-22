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
int a[200005],b[200005];
int solve(V<int> v,int num){
	int n=0,re=0;
	for(auto u:v)a[++n]=u;
	a[n+1]=a[n+2]=a[n+3]=0;
	int r,sum=0;
	FOR(i,1,n){
		if(i&1)sum+=a[i];else sum-=a[i];
	}
	if(n&1){
		sum-=a[n]*2;
		r=n-2;
	}else{
		r=n-1;
	}
	int tr=r;
//	cout<<tr<<' ';
	for(int i=1;i<n;i+=2){
		while(r>=i&&sum-a[r]*2>num){
			sum-=a[r]*2;r-=2;
		}
		gmax(r,i);
		if(sum>num)re+=max(0ll,(tr-r)/2+1);
		sum+=a[i+1]*2;
	}
	r,sum=0;
	FOR(i,1,n){
		if(i&1)sum-=a[i];else sum+=a[i];
	}
	sum+=2*a[1];
	if(n&1){
		r=n-1;
	}else{
		sum-=a[n]*2;
		r=n-2;
	}
	tr=r;
//	cout<<tr<<'\n';
//	cout<<re<<' ';
	for(int i=2;i<n;i+=2){
		while(r>=i&&sum-a[r]*2>num){
			sum-=a[r]*2;r-=2;
		}
		gmax(r,i);
		if(sum>num)re+=max(0ll,(tr-r)/2+1);
		sum+=a[i+1]*2;
	}
//	cout<<re<<'\n';
	RE re;
}
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>b[n-i+1];
	int sum=0;
	if(n==1){
		cout<<1<<'\n';RE ;
	}else if(n==2){
		cout<<1+(b[1]!=b[2])<<'\n';RE ;
	}
	FOR(i,0,n){
		sum-=b[i];
	}
	int ans=0;
	for(int i=n;i>=1;i--)sum+=b[i]*2,ans+=sum>0;
	V<int> v;
	FOR(i,1,n)v.PB(b[i]);
	ans+=solve(v,0);
	v.clear();
	FOR(i,1,n-1)v.PB(b[i]);
	ans+=solve(v,-b[n]);
	v.clear();
	FOR(i,2,n)v.PB(b[i]);
	ans+=solve(v,b[1]);
	v.clear();
	FOR(i,2,n-1)v.PB(b[i]);
	ans+=solve(v,b[1]-b[n]);
	cout<<ans%998244353<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}