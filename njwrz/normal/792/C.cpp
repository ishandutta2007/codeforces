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
int dp[100005][3];
bool lst[100005][3];
char c[100005];
signed main(){
	scanf("%s",c+1);
	int n=strlen(c+1);
	FILL(dp,-1);
	dp[0][0]=0;
	FOR(i,1,n){
		FOR(j,0,2)if(dp[i-1][j]!=-1){
			int to=(j+(c[i]-'0'))%3;
			if(dp[i-1][j]>0||c[i]!='0'){
				if(dp[i][to]==-1){
					dp[i][to]=dp[i-1][j]+1;
					lst[i][to]=1;
				}else{
					if(dp[i][to]<dp[i-1][j]+1){
						dp[i][to]=dp[i-1][j]+1;
						lst[i][to]=1;
					}
				}
			}
			to=j;
			if(dp[i][to]==-1){
				dp[i][to]=dp[i-1][j];
				lst[i][to]=0;
			}else{
				if(dp[i][to]<dp[i-1][j]){
					dp[i][to]=dp[i-1][j];
					lst[i][to]=0;
				}
			}
		}
	}
	if(dp[n][0]==-1||dp[n][0]==0){
		FOR(i,1,n){
			if(c[i]=='0'){
				cout<<0;RE 0;
			}
		}
		cout<<-1;
	}else{
		V<char> v;
		int now=0;
		for(int i=n;i>=1;i--){
			if(lst[i][now]){
				v.PB(c[i]);
				now=(now-(c[i]-'0')%3+3)%3;
			}
		}
		reverse(ALL(v));
		for(auto u:v)cout<<u;
	}
	RE 0;
}