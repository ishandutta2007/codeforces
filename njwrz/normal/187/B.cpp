#pragma GCC optimize("Ofast")
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
using namespace std;
int p[65][65][65],dp[65][65][65];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	FOR(t,1,m){
		FOR(i,1,n){
			FOR(j,1,n)cin>>p[t][i][j];
		}
	}
	FOR(t,1,m){
		FOR(i,1,n){
			FOR(j,1,n){
				FOR(k,1,n)gmin(p[t][j][k],p[t][j][i]+p[t][i][k]);
			}
		}
	}
	FOR(i,1,n){
		FOR(j,1,n){
			dp[i][j][0]=1e17;
			FOR(t,1,m)gmin(dp[i][j][0],p[t][i][j]);
		}
	}
	FOR(t,1,n){
		FOR(i,1,n){
			FOR(j,1,n)dp[i][j][t]=dp[i][j][t-1];
		}
		FOR(i,1,n){
			FOR(j,1,n){
				FOR(k,1,n)gmin(dp[j][k][t],dp[j][i][t-1]+dp[i][k][0]);
			}
		}
	}
	int q1,q2,q3;
	FOR(i,1,q){
		cin>>q1>>q2>>q3;
		gmin(q3,n);
		cout<<dp[q1][q2][q3]<<'\n';
	}
	RE 0;
}