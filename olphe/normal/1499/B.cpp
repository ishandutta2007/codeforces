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

void Solve() {
	string s;
	cin >> s;
	s.push_back('1');
	vector<vector<int>>dp(s.size() + 1, vector<int>(2));
	dp[0][0] = 1;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 2; j++) {
			if (s[i] == '0') {
				dp[i + 1][0] |= dp[i][0];
				if (i - 1 >= 0)dp[i + 1][0] |= dp[i - 1][0];
			}
			else {
				dp[i + 1][1] |= dp[i][0] | dp[i][1];
				if (i - 1 >= 0)dp[i + 1][1] |= dp[i - 1][0] | dp[i - 1][1];
			}
		}
	}
	if (dp.back().front() || dp.back().back())cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}

}