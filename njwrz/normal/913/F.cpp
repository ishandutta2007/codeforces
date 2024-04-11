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
using namespace std;
const int mod=998244353;
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
int n,A,B,p,pw[2000005],dp[2005],f[2005],val[2005][2005],pw2[2000005],f1[2005],f2[2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>A>>B;
	p=A*POW(B,mod-2)%mod;
	pw[0]=pw2[0]=1;
	FOR(i,1,n)pw[i]=pw[i-1]*p%mod,pw2[i]=pw2[i-1]*(mod+1-p)%mod;
	dp[1]=1;
	f[1]=0;
	val[0][0]=1;
	FOR(i,0,n)FOR(j,0,n){
		add(val[i+1][j],val[i][j]*pw2[j]%mod);
		add(val[i][j+1],val[i][j]*pw[i]%mod);
	}
	f1[1]=1;f2[1]=0;
	FOR(i,2,n){
		dp[i]=1;
		rep(j,1,i){
			add(dp[i],mod-val[j][i-j]*dp[j]%mod);
		}
		rep(j,1,i){
			add(f1[i],f1[j]*dp[i-j]%mod*val[j][i-j]%mod);
			add(f2[i],f2[j]*dp[i-j]%mod*val[j][i-j]%mod);
			add(f2[i],f1[j]*f[i-j]%mod*dp[i-j]%mod*val[j][i-j]%mod);
		}
		f[i]=f2[i];
		add(f[i],i*(i-1)/2);
//		cout<<dp[i]*16%mod<<' ';
//		cout<<(f1[i]+dp[i])%mod<<'\n';
		f[i]=f[i]*POW(mod+1-dp[i],mod-2)%mod;
		add(f1[i],dp[i]);
		add(f2[i],dp[i]*f[i]%mod);
	}
	cout<<f[n];
	RE 0;
}