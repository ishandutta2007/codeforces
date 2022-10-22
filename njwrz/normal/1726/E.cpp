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
using namespace std;
const int mod=998244353;
int dp[300005];

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
int val[300005];
void solve(){
	int x;
	cin>>x;
	int ans=0;
	for(int i=0;i*4<=x;i++){
		add(ans,C(x-i*2,i*2)*POW(2,i)%mod*dp[x-i*4]%mod*val[i]%mod);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,300000){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	dp[0]=1;
	rep(i,0,300000){
		add(dp[i+1],dp[i]);
		add(dp[i+2],dp[i]*(i+1)%mod);
	}
	val[0]=1;
	rep(i,1,300000)val[i]=val[i-1]*(2*i-1)%mod;
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}