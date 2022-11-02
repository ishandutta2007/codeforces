#include <bits/stdc++.h>
#define int long long
#define inf (1LL << 60)

using namespace std;
const int mod = 998244353;

int A[500002];
int dp[500002][2];
void solve(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i <= n + 1; i++) dp[i][0] = dp[i][1] = 0;
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		dp[A[i] + 1][0] += dp[A[i] + 1][0] + dp[A[i]][0];
		dp[A[i] + 1][1] += dp[A[i] + 1][1];
		dp[A[i] - 1][1] += dp[A[i] - 1][0] + dp[A[i] - 1][1];
		
		dp[A[i] + 1][0] %= mod;
		dp[A[i] + 1][1] %= mod;
		dp[A[i] - 1][1] %= mod;
	}
	int ans = 0;
	for(int i = 0; i <= n + 1; i++){
		ans += dp[i][0] + dp[i][1];
		ans %= mod;
	}
	ans -= 1;
	ans = (ans + mod) % mod;
	cout << ans << endl;
}
int32_t main(){
	int t;
	cin >> t;
	while(t--) solve(); 
}