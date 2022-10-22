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
char c[55];
int dp[55][105][605];
int A=52,B=250;
signed main(){
	scanf("%s",c+2);
	int len=strlen(c+2);
	FOR(i,2,len+1){
		c[i]-='0';
	} 
	FOR(i,0,len+1){
		FOR(j,0,A+A){
			FOR(k,0,B+B)dp[i][j][k]=2147483647;
		}
	}
	dp[0][A][B]=0;
	FOR(i,1,len+1){
		FOR(j,-A,A){
			FOR(k,-B,B){
				if(dp[i-1][j+A][k+B]>=2147483647){
					continue;
				}
				FOR(copy,-6,6){
					int nj=j*10+k-c[i]+copy;
					if(nj<-A||nj>A)continue;
					gmin(dp[i][nj+A][k+copy+B],dp[i-1][j+A][k+B]+abs(copy)*(len-i+2));
				}
			}
		}
	}
	int ans=2147483647;
	FOR(i,-B,B)gmin(ans,dp[len+1][A][i+B]);
	cout<<ans;
	RE 0;
}