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
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n; 
int dp[105][105][2],siz[105];
int p[105][2],mod=1e9+7;
V<int> v[105];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
void dfs(int x,int y=-1){
	dp[x][0][1]=1;
	dp[x][0][0]=1;
	siz[x]=1;
	for(auto u:v[x])if(u!=y){
		dfs(u,x);
		FILL(p,0);
		FOR(i,0,siz[x]-1){
			FOR(j,0,siz[u]-1){
				rep(k1,0,2)rep(k2,0,2){
					if(k1+k2<=1)add(p[i+j][k1+k2],dp[x][i][k1]*dp[u][j][k2]%mod);
					if(k2)add(p[i+j+1][k1],dp[x][i][k1]*dp[u][j][k2]%mod);
				}
			}
		}siz[x]+=siz[u];
		FOR(i,0,siz[x])dp[x][i][0]=p[i][0],dp[x][i][1]=p[i][1];
	}
}
int C[105][105],sum[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,0,n){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1);
	int ans=0;
	rep(j,0,n){
		FOR(i,0,j){
			int t=dp[1][i][1];
			rep(_,1,i)t=t*n%mod;
			if(!i)t=1;
			t=t*C[n-1-i][j-i]%mod;
			if((j-i)&1){
				add(ans,mod-t);
			}else add(ans,t);
		}
		sum[n-j]=ans;
	}
	FOR(i,1,n)cout<<(sum[i]-sum[i+1]+mod)%mod<<' ';
	RE 0;
}