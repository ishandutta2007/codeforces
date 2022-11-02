#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int dp[200005],r,g,mod=1e9+7,_dp[200005];
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>r>>g;
	int n=1;
	while((n+1)*(n+2)/2<=r+g)n++;
	dp[0]=1;
	FOR(i,1,n){
		FILL(_dp,0);
		FOR(j,0,min(r,i*(i+1)/2)){
			if(j>=i)_dp[j]=(_dp[j]+dp[j-i])%mod;
			if(i*(i+1)/2-j<=g)_dp[j]=(_dp[j]+dp[j])%mod;
		}
		FOR(j,0,min(r,i*(i+1)/2))dp[j]=_dp[j];
	}
	int ans=0;
	FOR(i,0,r)ans=(ans+dp[i])%mod;
	cout<<ans;
	RE 0;
}