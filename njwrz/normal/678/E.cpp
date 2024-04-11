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
double dp[1<<18][18];
double a[18][18];
signed main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<1;RE 0;
	}
	rep(i,0,n){
		rep(j,0,n)cin>>a[i][j];
	}
	dp[(1<<n)-1][0]=1;
	for(int i=(1<<n)-2;i>0;i--){
		rep(j,0,n)if(i&(1<<j)){
			rep(k,0,n)if(!(i&(1<<k))){
				gmax(dp[i][j],dp[i|(1<<k)][j]*a[j][k]+dp[i|(1<<k)][k]*a[k][j]);
			}
		}
	}
	double ans=0;
	rep(i,0,n)gmax(ans,dp[1<<i][i]);
	printf("%.10f",ans);
	RE 0;
}