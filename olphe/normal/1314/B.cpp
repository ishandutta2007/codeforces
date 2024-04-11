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

	cin >> N >> K;
	if (!K) {
		cout << 0 << endl;
		return 0;
	}
	vector<int>v((1 << N) + 1);
	for (int i = 0; i < K; i++) {
		cin >> M;
		v[M]++;
	}
	for (int i = 1; i <= 1 << N; i++) {
		v[i] += v[i - 1];
	}

	vector<vector<vector<vector<long long int>>>>dp(N + 1, vector<vector<vector<long long int>>>((1 << N) + 1, vector<vector<long long int>>(2,vector<long long int>(2,-MOD))));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= (1 << N); j += 1 << i) {
			if (i == 1) {
				if (v[j + (1 << i) - 1] - v[j - 1] == 1) {
					dp[i][j][0][1] = 1;
					dp[i][j][1][0] = 1;
				}
				if (v[j + (1 << i) - 1] - v[j - 1] == 2) {
					dp[i][j][1][1] = 1;
				}
			}
			if (v[j + (1 << i) - 1] - v[j - 1] == 0) {
				dp[i][j][0][0] = 0;
				continue;
			}
			for (int a = 0; a <= 1; a++) {
				for (int b = 0; b <= 1; b++) {
					for (int c = 0; c <= 1; c++) {
						for (int d = 0; d <= 1; d++) {
							if (!(a&&c)) {
								int add = 1 + (a || c) + (b || d);
								dp[i][j][0][1] = max(dp[i][j][0][1], dp[i - 1][j][a][b] + dp[i - 1][j + (1 << (i - 1))][c][d] + add);
							}
							if (a + b + c + d == 1 && !b && !d) {
								int add = 1;
								dp[i][j][1][0] = max(dp[i][j][1][0], dp[i - 1][j][a][b] + dp[i - 1][j + (1 << (i - 1))][c][d] + add);
							}
							if (a + b + c + d >= 2 && (a || c)) {
								int add = 2 + (b || d);
								dp[i][j][1][1] = max(dp[i][j][1][1], dp[i - 1][j][a][b] + dp[i - 1][j + (1 << (i - 1))][c][d] + add);
							}
						}
					}
				}
			}
		}
	}
	long long int ans = 0;
	for (auto i : dp.back()[1])for (auto j : i)ans = max(ans, j);
	cout << ans + 1 << endl;
	return 0;
}