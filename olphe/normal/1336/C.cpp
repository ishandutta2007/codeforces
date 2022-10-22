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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s >> t;
	M = t.size();
	vector<vector<long long int>>dp(s.size(), vector<long long int>(s.size()));
	for (int i = 0; i < s.size(); i++) {
		if (i >= M || t[i] == s.front()) {
			dp[i][i] = 2;
		}
	}
	for (int i = 1; i < s.size(); i++) {
		for (int j = 0; j + i < s.size(); j++) {
			if (j >= M || s[i] == t[j]) {
				dp[j][j + i] += dp[j + 1][j + i];
				dp[j][j + i] %= MOD;
			}
			if (j + i >= M || s[i] == t[j + i]) {
				dp[j][j + i] += dp[j][j + i - 1];
				dp[j][j + i] %= MOD;
			}
		}
	}
	long long int ans = 0;
	for (int i = M - 1; i < s.size(); i++)ans += dp[0][i];
	ans %= MOD;
	cout << ans << endl;
}