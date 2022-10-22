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
int dp[10005][10005];
int n,m,r[10005]; 
char s[10005],t[10005];
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	FOR(i,0,n){
		FOR(j,0,m)dp[i][j]=1e9;
	}
	dp[0][0]=0;
	FOR(i,1,n){
		int cnt=0;
		FOR(j,i,n){
			cnt+=s[j]=='.'?-1:1;
			if(cnt<0)break;
			if(!cnt){
				r[i]=j;break;
			}
		}
	}
	rep(i,0,n){
		FOR(j,0,m){
			if(dp[i][j]>n)continue;
			if(j<m&&s[i+1]==t[j+1])gmin(dp[i+1][j+1],dp[i][j]);
			if(r[i+1])gmin(dp[r[i+1]][j],dp[i][j]);
			gmin(dp[i+1][j],dp[i][j]+1);
		}
	}
	if(dp[n][m]>n){
		cout<<-1;
	}else cout<<dp[n][m];
	RE 0;
}