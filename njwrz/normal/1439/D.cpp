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
int dp[505],mod,m,n,val[505];
int f[505][505],f2[505][505];
int C[505][505];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int get(int x){
	RE x*(x+1)/2;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>mod;
	FOR(i,0,n){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	dp[1]=2;dp[0]=1;
	FOR(i,2,m){
		FOR(j,1,i){
			int now=dp[j-1]*dp[i-j]%mod*C[i-1][j-1]%mod;
			add(dp[i],(i-j+1)*now%mod);
			add(val[i],val[j-1]*dp[i-j]%mod*C[i-1][j-1]%mod*(i-j+1)%mod);
			add(val[i],dp[j-1]*val[i-j]%mod*C[i-1][j-1]%mod*(i-j+1)%mod);
			add(val[i],get(i-j)*now%mod);
		}
		dp[i]=dp[i]*2%mod;
		val[i]=val[i]*2%mod;
	}
	f[0][0]=1;
	FOR(i,0,n)FOR(k,0,m)if(f[i][k]){
		add(f[i+1][k],f[i][k]);
		add(f2[i+1][k],f2[i][k]);
		FOR(j,i+1,n){
			int t=j-i;
			if(t+k>m)continue;
			add(f[j+1][k+t],f[i][k]*C[t+k][t]%mod*dp[t]%mod);
			add(f2[j+1][k+t],f2[i][k]*C[t+k][t]%mod*dp[t]%mod);
			add(f2[j+1][k+t],f[i][k]*C[t+k][t]%mod*val[t]%mod);
		}
	}
	int ans=0;
	cout<<f2[n+1][m];
	RE 0;
}