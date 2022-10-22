#include<bits/stdc++.h>
#define ll long long
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
double dp[55][55],dp2[55][55];
V<int> g[55];
int n,siz[55];
double C[55][55],f[55];
double d[55];
void dfs(int x,int y){
	siz[x]=1;
	dp[x][0]=1/2.0;
	for(auto u:g[x])if(u!=y){
		dfs(u,x);
		FILL(d,0);
		rep(i,0,siz[x])FOR(j,0,siz[u]){
			d[i+j]+=dp[x][i]*dp2[u][j]*C[i+j][j]*C[siz[x]-i-1+siz[u]-j][siz[x]-i-1];
		}
		siz[x]+=siz[u];
		rep(i,0,siz[x])dp[x][i]=d[i];
	}
	dp2[x][1]=1;
	siz[x]=1;
	for(auto u:g[x])if(u!=y){
		FILL(d,0);
		FOR(i,1,siz[x])FOR(j,0,siz[u]){
			d[i+j]+=dp2[x][i]*dp2[u][j]*C[i+j][j]*C[siz[x]-i+siz[u]-j][siz[x]-i];
		}
		siz[x]+=siz[u];
		FOR(i,1,siz[x])dp2[x][i]=d[i];
	}
	double sum=0;
	for(int i=siz[x];i>=0;i--){
		sum+=dp[x][i];
		dp2[x][i]+=sum;
	}
}
signed main(){
	cin>>n;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		g[x].PB(y);
		g[y].PB(x);
	}
	FOR(i,0,n){
		C[i][0]=1;
		FOR(j,1,i)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	f[0]=1;
	FOR(i,1,n)f[i]=f[i-1]*i;
	FOR(i,1,n){
		FILL(dp,0);FILL(dp2,0);
		double ans=1;
		dfs(i,-1);
		printf("%.10f\n",dp[i][0]*2/f[n-1]);
	}
	RE 0;
}