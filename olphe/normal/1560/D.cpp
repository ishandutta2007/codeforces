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
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

vector<string>t;

void Solve() {
	string s;
	cin >> s;
	int ans = 100;
	for (auto st : t) {
		vector<vector<int>>dp(s.size() + 1, vector<int>(st.size() + 1, 1000));
		dp[0][0] = 0;
		for (int i = 0; i <= s.size(); i++) {
			for (int j = 0; j <= st.size(); j++) {
				if (i < s.size()) {
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
				}
				if (i < s.size() && j < st.size() && s[i] == st[j]) {
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
				}
				if (i == s.size() && j < st.size()) {
					dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
				}
			}
		}
		ans = min(ans, dp.back().back());
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	N = 1;
	while (N < 1e18) {
		t.push_back(to_string(N));
		N <<= 1;
	}
	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}