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
#define clear() FOR(i,1,n)FOR(j,0,1)FOR(k,0,2)dp[i][j][k]=maxi
using namespace std;
int n,a[200005],dp[200005][2][3],maxi=1e9,ans;
void run(int p){
	FOR(i,3,n){
		FOR(j,0,1){
			gmin(dp[i][j][1],min(dp[i-1][!j][1],dp[i-1][!j][2])+(j!=a[i]));
			gmin(dp[i][j][2],dp[i-1][j][1]+(j!=a[i]));
		}
	}
	int co=p&2;
	co=co>0;
	int len=((p&1)==co)+1;
	FOR(j,0,1){
		FOR(k,1,2){
			if(j!=co||k+len<3){
				gmin(ans,dp[n][j][k]);
			}
		}
	}
}
void solve(){
	cin>>n;
	FOR(i,1,n){
		char c;
		cin>>c;
		a[i]=c=='R';
	}
	ans=1e9;
	clear();
	dp[2][0][2]=a[1]+a[2];
	run(0);
	clear();
	dp[2][1][1]=a[1]+(!a[2]);
	run(1);
	clear();
	dp[2][0][1]=(!a[1])+a[2];
	run(2);
	clear();
	dp[2][1][2]=(!a[1])+(!a[2]);
	run(3);
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}