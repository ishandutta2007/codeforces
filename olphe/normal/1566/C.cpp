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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	string s;
	cin >> s;
	string t;
	cin >> t;
	vector<int>dp(N + 1);
	vector<int>zero(N + 1);
	vector<int>one(N + 1);
	vector<vector<int>>zerop(N + 1);
	vector<vector<int>>onep(N + 1);
	for (int i = 0; i < N; i++) {
		zero[i + 1] = zero[i] + ((s[i] == '0') || (t[i] == '0'));
		one[i + 1] = one[i] + ((s[i] == '1') || (t[i] == '1'));
		zerop[zero[i + 1]].push_back(i + 1);
		onep[one[i + 1]].push_back(i + 1);
	}
	for (int i = 0; i < N; i++) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
		if (zero[N] != zero[i]) {
			dp[zerop[zero[i] + 1][0]] = max(dp[zerop[zero[i] + 1][0]], dp[i] + 1);
			if (one[N] != one[i]) {
				dp[max(zerop[zero[i] + 1][0], onep[one[i] + 1][0])] = max(dp[max(zerop[zero[i] + 1][0], onep[one[i] + 1][0])], dp[i] + 2);
			}
		}
	}
	cout << dp.back() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}