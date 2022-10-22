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

void func(vector<vector<int>>& edge, vector<vector<int>>& dp, int node, int p = -1) {
	dp[node].push_back(1);
	for (auto e : edge[node]) {
		if (e == p)continue;
		func(edge, dp, e, node);
		dp[e].insert(dp[e].begin(), 0);
		vector<int>box(max(dp[node].size(), dp[e].size()));
		for (int i = 0; i < dp[node].size(); i++) {
			for (int j = 0; j < dp[e].size(); j++) {
				if (i + j <= K) {
					box[max(i, j)] += 1LL * dp[node][i] * dp[e][j] % MOD;
					box[max(i, j)] %= MOD;
				}
				if (i <= K) {
					box[i] += 1LL * dp[node][i] * dp[e][j] % MOD;
					box[i] %= MOD;
				}
			}
		}
		dp[node] = box;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<vector<int>>dp(N);
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	func(edge, dp, 0);
	int ans = 0;
	for (int i = 0; i < dp[0].size(); i++) {
		if (i <= K) {
			ans += dp[0][i];
			ans %= MOD;
		}
	}
	cout << ans << endl;
}