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
int dp[65],maxi=1e9;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,sum=0;
	int ans=0;
	cin>>n;
	FOR(i,1,n){
		cin>>x;
		gmin(dp[x+30],sum);
		rep(j,0,x+30){
			gmin(dp[x+30],dp[j]);
			dp[j]=1e9;
		}
		sum+=x;
		FOR(j,0,60)gmax(ans,sum-j+30-dp[j]);
	}
	cout<<ans;
	RE 0;
}