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
	cin >> N >> K;
	vector<int>v(N);
	for (auto& i : v)cin >> i, i--;
	vector<vector<int>>p(N);
	for (int i = 0; i < N; i++) {
		p[v[i]].push_back(i);
	}
	for (int i = 0; i < N; i++) {
		p[i].push_back(N);
	}
	vector<vector<int>>dp(N + 1, vector<int>(N + 1, MOD));
	dp[0][0] = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], *lower_bound(p[i].begin(), p[i].end(), min((int)N,dp[i][j] + 1)));
		}
	}
	for (int i = N; i >= K; i--) {
		if (dp[i][K] < N) {
			cout << N - i << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}