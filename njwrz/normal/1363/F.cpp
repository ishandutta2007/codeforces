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
int cnts[2005][30],cntt[2005][30]; 
char s[2005],t[2005];
int dp[2005][2005],n;
void solve(){
	scanf("%d%s%s",&n,s+1,t+1);
	FILL(cnts[n+1],0);
	FILL(cntt[n+1],0);
	for(int i=n;i>=1;i--){
		FOR(j,0,25)cnts[i][j]=cnts[i+1][j],cntt[i][j]=cntt[i+1][j];
		cnts[i][s[i]-'a']++;
		cntt[i][t[i]-'a']++;
	}
	FOR(i,0,25){
		if(cnts[1][i]!=cntt[1][i]){
			puts("-1");RE;
		}
	}
	FOR(i,1,n){
		FOR(j,1,n){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(s[i]==t[j]){
				bool f=1;
				FOR(k,0,25)if(cnts[i][k]<cntt[j][k]){
					f=0;break;
				}
				if(f)dp[i][j]=dp[i-1][j-1]+1;
			}
		}
	}
	printf("%d\n",n-dp[n][n]);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
	RE 0;
}