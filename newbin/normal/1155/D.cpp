#include<iostream>
#define ll long long
using namespace std;
const int maxn = 3e5 + 50;
ll dp[maxn][3];
ll a[maxn];
ll x;
int n;
int main(){
	cin>>n>>x;
	ll ans = 0;
	for(int i = 1;i <= n;++i){
		scanf("%I64d",&a[i]);
		dp[i][0] = max(a[i],dp[i-1][0] + a[i]);
		ans = max(ans,dp[i][0]);
		
		dp[i][1] = max(dp[i-1][0] + x*a[i],dp[i-1][1] + x*a[i]);
		dp[i][1] = max(dp[i][1],x*a[i]);
		ans = max(ans,dp[i][1]);
		
		dp[i][2] = max(dp[i-1][1] + a[i],dp[i-1][2] + a[i]);
		dp[i][2] = max(dp[i][2],a[i]);
		ans = max(ans,dp[i][2]);
	}
	cout<<ans<<endl;
}