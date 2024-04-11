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
#include "iomanip"
#include "cmath"
#include "random"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<char>v(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	v[0] = 'f';
	vector<vector<long long int>>dp(N + 1, vector<long long int>(N + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		if (v[i - 1] == 'f') {
			for (int j = 1; j <= N; j++) {
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
		else {
			vector<long long int>sum(N + 1);
			sum[N] = dp[i - 1][N];
			for (int j = N - 1; j >= 1; j--) {
				sum[j] = sum[j + 1] + dp[i - 1][j];
				sum[j] %= MOD;
			}
			for (int j = 1; j <= N; j++) {
				dp[i][j] = sum[j];
			}
		}
	}
	long long int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += dp[N][i];
	}
	ans %= MOD;
	cout << ans << endl;
	return 0;
}