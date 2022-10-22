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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (N < 4) {
		cout << 0 << endl;
		return 0;
	}
	vector<vector<vector<long long>>>dp(N + 55, vector<vector<long long>>(N + 55, vector<long long>(N * N + 55)));
	dp[1][1][0] = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= i; j++) {
			for (int k = j - 1; k <= i * i; k++) {
				for (int l = 1; l <= i + 1; l++) {
					dp[i + 1][l][k + l - 1] += dp[i][j][k];
					dp[i + 1][l][k + l - 1] %= M;
				}
			}
		}
	}
	vector<long long>num(N + 1);
	long long ans = 0;
	for (int i = 2; i <= N; i++) {
		vector<vector<long long>>sum(N + 1, vector<long long>(N * N + 1,0));
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= i * i; k++) {
				sum[j][k] = dp[i][j][k];
			}
		}
		for (int j = 0; j <= N; j++) {
			for (int k = 1; k <= i * i; k++) {
				sum[j][k] += sum[j][k - 1];
			}
		}
		for (int j = N - 1; j >= 0; j--) {
			for (int k = 0; k <= i * i; k++) {
				sum[j][k] += sum[j + 1][k];
			}
		}
		for (int j = 1; j < N; j++) {
			for (int k = 1; k <= i * i; k++) {
				num[i] += (sum[j + 1][k - 1])%M * dp[i][j][k];
				num[i] %= M;
			}
		}
	}
	for (int i = 2; i <= N; i++) {
		long long add = num[i];
		for (int j = 0; j < N - i; j++) {
			add *= (N - j);
			add %= M;
		}
		ans += add;
		ans %= M;
	}
	cout << ans << endl;
}