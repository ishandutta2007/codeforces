/*

DP





ll int
 dp 










*/
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
int sdp[5005][5005],a[5005],dp[5005][5005],tdp[5005][7];
int it[100005];
bool f[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i],f[a[i]]=1;
	int cnt=0;
	FOR(i,2,100000){
		if(f[i]&&f[i-1]){
			it[i]=++cnt;
			if(!it[i-1])it[i-1]=++cnt;
		}
	}
	int ans=0;
	FOR(i,0,n){
		FOR(j,i+1,n){
			dp[i][j]=2-(i==0);
			gmax(dp[i][j],tdp[i][a[j]%7]+1);
			if(i)gmax(dp[i][j],dp[0][i]+1);
			int now=it[a[j]];
			if(now){
				int L=it[a[j]-1],R=it[a[j]+1];
				if(L){
					gmax(dp[i][j],sdp[L][i]+1);
				}
				if(R){
					gmax(dp[i][j],sdp[R][i]+1);
				}
			}
			gmax(tdp[i][a[j]%7],dp[i][j]);
			gmax(tdp[j][a[i]%7],dp[i][j]);
			if(it[a[j]])gmax(sdp[it[a[j]]][i],dp[i][j]);
			if(it[a[i]])gmax(sdp[it[a[i]]][j],dp[i][j]);
			gmax(ans,dp[i][j]);
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
		}
	}
	cout<<ans;
	RE 0;
}