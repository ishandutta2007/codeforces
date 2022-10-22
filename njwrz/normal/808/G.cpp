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
char c[100005],s[100005];
bool f[100005];
int dp[100005],p[100005];
signed main(){
	scanf("%s%s",c+1,s+1);
	int n=strlen(c+1),m=strlen(s+1);
	if(n<m){
		cout<<0;RE 0;
	}
	FOR(i,1,m){
		f[i]=1;
		FOR(j,i+1,m){
			if(s[j]!=s[j-i]){
				f[i]=0;break;
			}
		}
	}
	int ans=0;
	rep(i,1,m)dp[i]=-1e9; 
	FOR(i,m,n){
		bool ff=1;
		dp[i]=-1e9;
		for(int j=i;j>=i-m+1;j--){
			if(c[j]!='?'&&c[j]!=s[m+j-i]){
				ff=0;break;
			}
			if(f[i-j+1])gmax(dp[i],dp[j-1]+1);
			if(j==i-m+1)gmax(dp[i],p[j-1]+1);
		}
		p[i]=max(p[i-1],dp[i]);
		gmax(ans,dp[i]);
	}
	cout<<ans;
	RE 0;
}