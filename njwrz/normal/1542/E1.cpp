#include<bits/stdc++.h>
#define ll long long
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
using namespace std;
int n,mod;
int dp[505][505*255],C[505][505],p[505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>mod;
	p[0]=1;
	FOR(i,1,n)p[i]=1ll*p[i-1]*i%mod;
	int T=n*(n-1)/2;
	dp[0][T]=1;
	C[0][0]=1;
	FOR(i,1,n){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	FOR(i,1,n){
		int m=(i-1)*(i-2)/2;
		FOR(j,-m,m){
			FOR(k,-i+1,i-1){
				dp[i][k+j+T]=(dp[i][k+j+T]+1ll*dp[i-1][j+T]*min(i-k,k+i))%mod;
			}
		}
	}
	FOR(i,1,n){
		int m=(i-1)*i/2;
		for(int j=m;j>=-m;j--)dp[i][j+T]=(dp[i][j+T+1]+dp[i][j+T])%mod;
	}
	int ans=0;
	rep(i,1,n){
		rep(j,1,n-i+1){
			FOR(k,j+1,n-i+1){
				ans=(ans+1ll*dp[n-i][k-j+T+1]*C[n][i-1]%mod*p[i-1])%mod;
//				cout<<i<<' '<<j<<' '<<k<<' '<<1ll*dp[n-i][k-j+T+1]*C[n][i-1]%mod*p[i-1]<<'\n';
			}
		}
	}
	cout<<ans;
	RE 0;
}