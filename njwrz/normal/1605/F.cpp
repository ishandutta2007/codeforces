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
int mod,n,k;
int dp[85][85],C[85][85];
int pw[6405],f[85][85],p[85][85];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int get(int x,int y){
	int re=1;
	FOR(i,x-y+1,x)re=re*(i+mod)%mod;
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>mod;
	FOR(i,0,80){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	pw[0]=1;
	FOR(i,1,6400)pw[i]=pw[i-1]*2%mod;
	FOR(i,1,n)FOR(j,1,k){
		FOR(tj,0,j){
			if((j-tj)&1)add(f[i][j],mod-C[j][tj]*get(pw[tj]-1,i)%mod);
			else add(f[i][j],C[j][tj]*get(pw[tj]-1,i)%mod);
		}
	}
	FOR(i,1,n)FOR(j,0,k){
		FOR(tj,0,j){
			if((j-tj)&1)add(p[i][j],mod-C[j][tj]*(pw[tj*i])%mod);
			else add(p[i][j],C[j][tj]*(pw[tj*i])%mod);
		}
	}
	dp[0][0]=1;
	FOR(i,1,n)FOR(j,0,k){
		dp[i][j]=p[i][j];
		rep(ti,0,i-((n&1)&&i==n))rep(tj,0,j)
			add(dp[i][j],mod-C[i][ti]*dp[ti][tj]%mod*C[j][tj]%mod*f[i-ti][j-tj]%mod*pw[tj*(i-ti)]%mod);
	}
//	cout<<f[2][1]<<' ';
	int ans=0;
	FOR(i,0,k)add(ans,dp[n][i]*C[k][i]%mod);
	cout<<ans;
	RE 0;
}