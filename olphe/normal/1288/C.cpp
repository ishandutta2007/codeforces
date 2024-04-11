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
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<vector<long long int>>>dp(M, vector<vector<long long int>>(N + 1, vector<long long int>(N + 1)));
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			dp[0][i][j] = 1;
		}
	}
	for (int i = 0; i < M - 1; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = j; k < N; k++) {
				dp[i + 1][j][0] += dp[i][j][k];
				dp[i + 1][j][k + 1] += MOD - dp[i][j][k];
				dp[i + 1][N][0] += MOD - dp[i][j][k];
				dp[i + 1][N][k + 1] += dp[i][j][k];
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)dp[i + 1][j][k] %= MOD;
		}
		for (int j = 0; j < N; j++) {
			for (int k = 1; k < N; k++) {
				dp[i + 1][j][k] += dp[i + 1][j][k - 1];
				dp[i + 1][j][k] %= MOD;
			}
		}
		for (int j = 0; j < N; j++) {
			for (int k = 1; k < N; k++) {
				dp[i + 1][k][j] += dp[i + 1][k - 1][j];
				dp[i + 1][k][j] %= MOD;
			}
		}
	}
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			ans += dp.back()[i][j];
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}