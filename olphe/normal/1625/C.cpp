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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<int>p(N);
	vector<int>v(N);
	for (auto& i : p)cin >> i;
	for (auto& i : v)cin >> i;
	p.push_back(M);
	vector<vector<int>>dp(N + 1, vector<int>(N + 1,INT_MAX));
	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[i][j] == INT_MAX)continue;
			for (int k = i + 1; k <= N; k++) {
				dp[k][j + 1] = min(dp[k][j + 1], dp[i][j] + (p[k] - p[i]) * v[i]);
			}
		}
	}
	int ans = INT_MAX;
	for (int i = N - K; i <= N; i++) {
		ans = min(ans, dp[N][i]);
	}
	cout << ans << endl;
}