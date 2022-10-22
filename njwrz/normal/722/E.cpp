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
int n,m,k,s;
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
int dp[2005][25],sum[25];
P<int,int> p[2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k>>s;
	f[0]=f[1]=inv[1]=finv[0]=finv[1]=1;
	FOR(i,2,n+m){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	FOR(i,1,k)cin>>p[i].F>>p[i].S;
	sort(p+1,p+k+1);
	p[0]=MP(1,1);
	dp[0][0]=1;
	rep(i,0,k)FOR(j,0,20)if(dp[i][j]){
		FOR(to,i+1,k)if(p[to].S>=p[i].S){
			add(dp[to][j],mod-dp[i][j]*C(p[to].S-p[i].S+p[to].F-p[i].F,p[to].F-p[i].F)%mod);
			add(dp[to][j+1],dp[i][j]*C(p[to].S-p[i].S+p[to].F-p[i].F,p[to].F-p[i].F)%mod);
		}
	}
	FOR(i,0,k)FOR(j,0,20)if(dp[i][j]){
		add(sum[j],dp[i][j]*C(n-p[i].F+m-p[i].S,m-p[i].S)%mod);
	}
	int ans=0;
	FOR(j,0,20){
		add(ans,sum[j]*(s-1)%mod);
		s=(s+1)/2;
	}
	ans=ans*POW(C(n-1+m-1,n-1),mod-2)%mod;
	add(ans,1);
	cout<<ans;
	RE 0;
}