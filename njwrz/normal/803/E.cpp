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
char c[1005];
bool dp[1005][2005];
int lst[1005][2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	FOR(i,1,n)cin>>c[i];
	dp[0][1001]=1;
	FOR(i,1,n){
		FOR(j,-i,i){
			if(c[i]=='D'){
				dp[i][j+1001]=dp[i-1][j+1001];
			}else if(c[i]=='W'){
				dp[i][j+1001]=dp[i-1][j+1000];
			}else if(c[i]=='L'){
				dp[i][j+1001]=dp[i-1][j+1002];
			}else{
				if(dp[i-1][j+1000]){
					dp[i][j+1001]=1;
					lst[i][j+1001]=0;
				}
				if(dp[i-1][j+1002]){
					dp[i][j+1001]=1;
					lst[i][j+1001]=1;
				}
				if(dp[i-1][j+1001]){
					dp[i][j+1001]=1;
					lst[i][j+1001]=2;
				}
			}
		}
		if(i!=n)dp[i][k+1001]=0,dp[i][-k+1001]=0;
	}
	if(dp[n][k+1001]||dp[n][-k+1001]){
		int now=k+1001;
		if(dp[n][-k+1001])now=-k+1001;
		V<char> v;
		for(int i=n;i>=1;i--){
			if(c[i]=='D'){
				v.PB('D');
			} else if(c[i]=='W'){
				v.PB('W');now--;
			}else if(c[i]=='L'){
				v.PB('L');now++;
			}else{
				if(lst[i][now]==1){
					now++;v.PB('L');
				}else if(lst[i][now]==0){
					now--;v.PB('W');
				}else{
					v.PB('D');
				}
			}
		}
		reverse(ALL(v));
		for(auto u:v)cout<<u;
	}else cout<<"NO";
	RE 0;
}