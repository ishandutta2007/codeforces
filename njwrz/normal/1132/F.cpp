#pragma GCC optimize("Ofast")
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
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int dp[505][505];
int n;
char c[505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>c[i];
	FOR(i,0,n+1){
		FOR(j,0,n+1)dp[i][j]=1e9;
	}
	FOR(i,1,n+1)dp[i][i-1]=0;
	FOR(k,1,n){
		FOR(l,1,n-k+1){
			int r=l+k-1;
			dp[l][r]=1+dp[l+1][r];
//			cout<<dp[l][r]<<' ';
			FOR(mid,l+1,r){
				if(c[l]==c[mid]){
					gmin(dp[l][r],dp[l+1][mid-1]+dp[mid][r]);
				}
			}
		}
//		cout<<'\n';
	}
	cout<<dp[1][n];
	RE 0;
}