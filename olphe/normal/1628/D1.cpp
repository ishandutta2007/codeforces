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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M >> K;
	vector<vector<long long>>dp(N + 1, vector<long long>(M + 1));
	//vector<vector<long double>>dp(N + 1, vector<long double>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (j > M)break;
			dp[i][j] = (dp[i - 1][j] + MOD + dp[i - 1][j - 1]) * (MOD + 1) / 2;
			dp[i][j] %= MOD;
			//dp[i][j]
		}
		if (i <= M) {
			dp[i][i] = i * K % MOD;
		}
	}
	cout << dp[N][M] << endl;
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