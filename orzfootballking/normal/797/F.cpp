/*

DP





ll int
 dp 










*/
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
P<int,int> p[5005];
int n,m,a[5005],dp[5005][5005],sum[5005],to[2][5005];
P<int,int> num[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,m){
		cin>>p[i].F>>p[i].S;
	}
	sort(p+1,p+m+1);
	sort(a+1,a+n+1);
	FOR(i,1,m){
		sum[i]=sum[i-1]+p[i].S; 
	}
	FOR(i,0,m){
		FOR(j,0,n)dp[i][j]=1e18;
	}
	if(sum[m]<n){
		cout<<-1;RE 0;
	}
	FOR(i,1,m){
		dp[i][0]=0;
		int l=0,r=1;
		num[1]=MP(0,0);
		FOR(j,1,min(sum[i],n)){
			while(l<=r&&j-num[l].F>p[i].S)l++;
			while(l<=r&&num[r].S>dp[i][j])r--;
			num[++r]=MP(j,dp[i][j]);
//			cout<<dp[i][j]<<' ';
			gmin(dp[i][j],num[l].S);
		}
//		cout<<'\n';
		FOR(now,0,1)FOR(j,1,n)to[now][j]=to[now][j-1]+abs(a[j]-p[i+now].F);
		FOR(j,1,min(sum[i],n)){
			dp[i][j]+=to[0][j];
			gmin(dp[i+1][j],dp[i][j]-to[1][j]);
		}
	}
	cout<<dp[m][n];
	RE 0;
}