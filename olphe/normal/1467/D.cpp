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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	vector<vector<long long int>>dp(N, vector<long long int>(M + 1));
	for (int i = 0; i < N; i++)dp[i][0] = 1;
	for (int j = 1; j <= M; j++) {
		for (int i = 0; i < N; i++) {
			if (i)dp[i][j] += dp[i - 1][j - 1];
			if (i + 1 < N)dp[i][j] += dp[i + 1][j - 1];
			dp[i][j] %= MOD;
		}
	}
	vector<long long int>weight(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			weight[i] += dp[i][j] * dp[i][M - j] % MOD;
		}
		weight[i] %= MOD;
	}
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += weight[i] * v[i];
		ans %= MOD;
	}
	while (K--) {
		cin >> L >> R;
		L--;
		ans += MOD - weight[L] * v[L] % MOD;
		v[L] = R;
		ans += weight[L] * v[L];
		ans %= MOD;
		cout << ans << endl;
	}
}