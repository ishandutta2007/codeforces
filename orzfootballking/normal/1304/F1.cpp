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
int n,m,k;
int ml[20005],mr[20005];
int dp[55][20005];
int a[55][20005]; 
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n>>m>>k;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>a[i][j];
			a[i][j]+=a[i][j-1];
		}
	}
	FOR(i,1,n){
		FOR(j,1,m-k+1){
			if(j-k>=1)gmax(dp[i][j],ml[j-k]);
			if(j+k<=m-k+1)gmax(dp[i][j],mr[j+k]);
			dp[i][j]+=a[i][j+k-1]-a[i][j-1];
			FOR(last,max(j-k+1,1),j)gmax(dp[i][j],dp[i-1][last]+a[i][j+k-1]-a[i][last+k-1]);
			FOR(last,j+1,min(m-k+1,j+k-1))gmax(dp[i][j],dp[i-1][last]+a[i][last-1]-a[i][j-1]);
			dp[i][j]+=a[i+1][j+k-1]-a[i+1][j-1];
		}
		FOR(j,1,m-k+1)ml[j]=max(ml[j-1],dp[i][j]);
		for(int j=m-k+1;j>=1;j--)mr[j]=max(mr[j+1],dp[i][j]);
//		FOR(j,1,m-k+1)cout<<dp[i][j]<<' ';
//		cout<<'\n';
	}
	int ans=0;
	FOR(j,1,m-k+1)gmax(ans,dp[n][j]);
	cout<<ans;
	RE 0;
}