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
const int mod=1e9+7;
int dp[55][55],f[55][55],sum[55][55];
int inv[55],finv[55];
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
int val[55];
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	int re=finv[y];
	FOR(i,x-y+1,x)re=re*i%mod;
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,n){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	dp[0][1]=sum[0][1]=1;
	FOR(i,1,n){
		FOR(j,1,51){
			rep(k,0,i){
				add(f[i][j],sum[k][j]*sum[i-k-1][j]%mod);
				add(f[i][j],mod-sum[k][j+1]*sum[i-k-1][j+1]%mod);
			}
			FOR(mul,1,n)val[mul]=C(f[i][j]+mul-1,mul);
			for(int ti=n;ti>=0;ti--)for(int tj=51;tj>=1;tj--)if(dp[ti][tj]){
				FOR(mul,1,n){
					if(ti+mul*i>n||tj+mul*j>51)break;
					add(dp[ti+mul*i][tj+mul*j],dp[ti][tj]*val[mul]%mod);
				}
			}
		}
		for(int j=51;j>=1;j--)sum[i][j]=(dp[i][j]+sum[i][j+1])%mod;
	}
	cout<<dp[n][m];
	RE 0;
}