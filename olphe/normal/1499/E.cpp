#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	vector<vector<vector<long long int>>>dp(s.size() + 1, vector<vector<long long int>>(t.size() + 1, vector<long long int>(4)));
	long long int ans = 0;
	for (int i = 0; i <= s.size(); i++) {
		for (int j = 0; j <= t.size(); j++) {
			if (i) {
				dp[i][j][0]++;
				dp[i][j][0] %= MOD;
				if (i > 1) {
					if (s[i - 1] != s[i - 2]) {
						dp[i][j][0] += dp[i - 1][j][0];
						dp[i][j][0] %= MOD;
						dp[i][j][2] += dp[i - 1][j][2];
						dp[i][j][2] %= MOD;
					}
				}
				if (j) {
					if (s[i - 1] != t[j - 1]) {
						dp[i][j][2] += dp[i - 1][j][1];
						dp[i][j][2] %= MOD;
						dp[i][j][2] += dp[i - 1][j][3];
						dp[i][j][2] %= MOD;
					}
				}
			}
			if (j) {
				dp[i][j][1]++;
				dp[i][j][1] %= MOD;
				if (j > 1) {
					if (t[j - 1] != t[j - 2]) {
						dp[i][j][1] += dp[i][j - 1][1];
						dp[i][j][1] %= MOD;
						dp[i][j][3] += dp[i][j - 1][3];
						dp[i][j][3] %= MOD;
					}
				}
				if (i) {
					if (t[j - 1] != s[i - 1]) {
						dp[i][j][3] += dp[i][j - 1][0];
						dp[i][j][3] %= MOD;
						dp[i][j][3] += dp[i][j - 1][2];
						dp[i][j][3] %= MOD;
					}
				}
			}
			ans += dp[i][j][2];
			ans += dp[i][j][3];
		}
	}
	cout << ans % MOD << endl;
}