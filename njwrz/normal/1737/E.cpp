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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int n;
const int mod=1e9+7;
int f[300005],inv[300005],finv[300005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
void pref(){
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
int pw[1000005],dp[1000005],sum[1000005];
void solve(){
	cin>>n;
	if(n==1){
		cout<<1<<'\n';RE ;
	}
	cout<<0<<'\n';
	int inv=POW(2,mod-2);
	pw[0]=1;
	dp[n]=2;
	FOR(i,1,n)pw[i]=pw[i-1]*inv%mod;
	sum[n]=2;sum[n+1]=0;
	for(int i=n-1;i>=1;i--){
		dp[i]=sum[i+1]-sum[min(i*2,n+1)];
		if(dp[i]<0)dp[i]+=mod;
		sum[i]=sum[i+1];
		add(sum[i],dp[i]);
	}
	FOR(i,2,n){
		int mul=pw[i-i/2-1];
		if(i==n){
			cout<<mul<<'\n';continue;
		}
		cout<<mul*dp[i]%mod*pw[n-i]%mod*pw[1]%mod<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}