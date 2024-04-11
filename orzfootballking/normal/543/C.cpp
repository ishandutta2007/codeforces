#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define	int long long
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
using namespace std;
int co[25][25],n,m,p[25][25],dp[1<<20],ms[25][25]; 
char c[25][25];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)FOR(j,1,m){
		cin>>c[i][j];
	}
	FOR(i,1,n)FOR(j,1,m)cin>>co[i][j];
	FOR(i,1,n){
		FOR(j,1,m){
			int maxi=0;
			FOR(k,1,n){
				if(c[i][j]==c[k][j]){
					p[i][j]+=co[k][j];
					ms[i][j]|=1<<(k-1);
					gmax(maxi,co[k][j]);
				}
			}
			p[i][j]-=maxi;
		}
	}
	int maxi=1e18;
	rep(j,0,1<<n)dp[j]=maxi;
	dp[0]=0;
	rep(mk,0,1<<n){
		if(dp[mk]==maxi)continue;
		FOR(i,1,n)if(!(mk&(1<<(i-1)))){
			FOR(j,1,m){
				gmin(dp[mk|ms[i][j]],dp[mk]+p[i][j]);
				gmin(dp[mk|(1<<(i-1))],dp[mk]+co[i][j]);
			}
		}
	}
	cout<<dp[(1<<n)-1];
	RE 0;
}