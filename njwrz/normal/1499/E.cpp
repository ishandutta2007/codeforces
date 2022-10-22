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
int dp[1005][1005][2],lsts[1005],lstc[1005];
int n,m,mod=998244353;char s[1005],c[1005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%s%s",s+1,c+1);
	n=strlen(s+1);
	m=strlen(c+1);
	lsts[1]=1;
	FOR(i,1,n){
		if(s[i]==s[i-1]){
			lsts[i]=1;
		}else lsts[i]=lsts[i-1]+1;
//		cout<<lsts[i]<<' ';
	}
//	cout<<'\n';
	lstc[1]=1;
	FOR(i,1,m){
		if(c[i]==c[i-1]){
			lstc[i]=1;
		}else lstc[i]=lstc[i-1]+1;
//		cout<<lstc[i]<<' ';
	}
//	cout<<'\n';
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,m){
			if(s[i]!=c[j])dp[i][j][0]=lstc[j];
			if(c[j]!=s[i])dp[i][j][1]=lsts[i];
			if(i>1){
				if(s[i]!=s[i-1])add(dp[i][j][0],dp[i-1][j][0]);
				if(s[i]!=c[j])add(dp[i][j][0],dp[i-1][j][1]);
			}
			if(j>1){
				if(c[j]!=s[i])add(dp[i][j][1],dp[i][j-1][0]);
				if(c[j]!=c[j-1])add(dp[i][j][1],dp[i][j-1][1]);
			}
			rep(k,0,2)add(ans,dp[i][j][k]);
		}
	}
	cout<<ans;
	RE 0;
}