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

int ncr[111][111];


void Solve() {
	cin >> N >> K;
	vector<vector<int>>edge(N, vector<int>(N, MOD));
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--, R--;
		edge[L][R] = 1;
		edge[R][L] = 1;
	}
	if (K == 2) {
		cout << N * (N - 1) / 2 << endl;
		return;
	}
	for (int i = 0; i < N; i++) {
		edge[i][i] = 0;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		vector<vector<int>>v;
		vector<int>sum(N);
		for (int j = 0; j < N; j++) {
			sum[edge[i][j]]++;
			if (edge[i][j] == 1) {
				vector<int>box(N);
				for (int k = 0; k < N; k++) {
					if (edge[i][k] == edge[j][k] + 1) {
						box[edge[i][k]]++;
					}
				}
				v.push_back(box);
			}
		}
		for (int j = 0; j < N; j++) {
			vector<long long>dp(K + 1);
			dp[0] = 1;
			for (auto k : v) {
				for (int l = K; l >= 0; l--) {
					if (l) {
						dp[l] += dp[l - 1] * k[j];
						dp[l] %= MOD;
					}
				}
			}
			ans += dp[K];
			ans %= MOD;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	ncr[0][0] = 1;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j <= i; j++) {
			ncr[i + 1][j] += ncr[i][j];
			ncr[i + 1][j + 1] += ncr[i][j];
			ncr[i + 1][j] %= MOD;
			ncr[i + 1][j + 1] %= MOD;
		}
	}
	cin >> T;
	while (T--) {
		Solve();
	}
}