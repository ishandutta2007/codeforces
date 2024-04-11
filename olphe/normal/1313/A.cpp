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

void Solve() {
	int dp[11][11][11] = {};
	cin >> N >> M >> K;
	for (int i = 1; i < 8; i++) {
		for (int j = 7; j >= 0; j--) {
			for (int k = 7; k >= 0; k--) {
				for (int l = 7; l >= 0; l--) {
					int a = i & 4;
					int b = i & 2;
					int c = i & 1;
					dp[j + !!a][k + !!b][l + !!c] = max(dp[j + !!a][k + !!b][l + !!c], dp[j][k][l] + 1);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			for (int k = 0; k <= K; k++) {
				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}