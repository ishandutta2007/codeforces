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
int dp[55][55];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,0,50){
		FOR(j,0,50)dp[i][j]=1e9;
	}
	dp[0][0]=0;
	FOR(i,0,50){
		FOR(j,0,50)FOR(i1,0,i)FOR(j1,0,j){
			int t=(i-i1)*(i-i1)+(j-j1)*(j-j1);
			int now=sqrt(t);
			if(now*now==t){
				gmin(dp[i][j],dp[i1][j1]+1);
			}
		}
	}
	int T;
	cin>>T;
	while(T--){
		int x,y;
		cin>>x>>y;
		cout<<dp[x][y]<<'\n';
	}
	RE 0;
}