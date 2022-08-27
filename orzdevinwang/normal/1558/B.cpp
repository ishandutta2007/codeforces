#include<bits/stdc++.h>
#define ll long long
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define vi vector < int > 
#define sz(a) ((int) a.size()) 
using namespace std;
const int N = 8e6 + 7;
int n, mod, dp[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> mod;
	dp[1] = 1, dp[2] = mod - 1;
	L(i, 1, n) {
		(dp[i] += dp[i - 1]) %= mod;
		L(z, 2, n / i) (dp[i * z] += dp[i]) %= mod, (dp[(i + 1) * z] += mod - dp[i]) %= mod;
		(dp[i + 1] += dp[i]) %= mod;
	}
	cout << dp[n] << "\n";
	return 0;
}