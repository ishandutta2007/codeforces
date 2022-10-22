#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define rc ((x<<1)^1)
#define y1 yyyy1111
#define mod 998244353
using namespace std;
int n;
int f[300005],inv[300005],finv[300005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
int val[300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	int T=n-(n-1)/2,del=0;
	for(int i=n;i>=1;i--){
		val[i]=f[n-i]*f[n-T]%mod*finv[n-T-i+1]%mod;
		add(val[i],mod-del);
		add(del,(val[i]+del)*inv[i-1]%mod);
	}
	FOR(i,1,n)cout<<val[i]<<' ';
	RE 0;
}