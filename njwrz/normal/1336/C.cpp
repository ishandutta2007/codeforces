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
int dp[3005][3005]; 
int n,m,mod=998244353;
char a[3005],b[3005];
signed main(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);m=strlen(b+1);
	FOR(i,1,n){
		if(i>m||a[1]==b[i])dp[i][i]=1;
	}
	int l,r;
	rep(i,1,n){
		FOR(j,1,n-i+1){
			l=j;r=j+i-1;
			if(l>1&&(l-1>m||b[l-1]==a[i+1]))dp[l-1][r]=(dp[l-1][r]+dp[l][r])%mod;
			if(r+1<=n&&(r+1>m||b[r+1]==a[i+1]))dp[l][r+1]=(dp[l][r+1]+dp[l][r])%mod;
		}
	}
	int ans=0;
	FOR(i,m,n){
		ans=(ans+dp[1][i])%mod;
	}
	cout<<ans*2%mod;
	RE 0;
}