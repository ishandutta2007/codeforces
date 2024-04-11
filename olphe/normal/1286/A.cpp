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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	int even = N / 2;
	int odd = N - even;
	vector<vector<vector<int>>>dp(N, vector<vector<int>>(odd + 1, vector<int>(2, MOD)));
	if (v[0] == 0) {
		dp[0][odd - 1][1] = 0;
		dp[0][odd][0] = 0;
	}
	else if (v[0] & 1) {
		dp[0][odd - 1][1] = 0;
	}
	else {
		dp[0][odd][0] = 0;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= odd; j++) {
			if (v[i] == 0) {
				if (j) {
					dp[i][j - 1][1] = min(dp[i][j - 1][1], dp[i - 1][j][0] + 1);
					dp[i][j - 1][1] = min(dp[i][j - 1][1], dp[i - 1][j][1] + 0);
				}
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + 0);
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + 1);
			}
			else if (v[i] & 1) {
				if (j) {
					dp[i][j - 1][1] = min(dp[i][j - 1][1], dp[i - 1][j][0] + 1);
					dp[i][j - 1][1] = min(dp[i][j - 1][1], dp[i - 1][j][1] + 0);
				}
			}
			else {
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + 0);
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + 1);
			}
		}
	}
	cout << min(dp.back()[0][0], dp.back()[0][1]) << endl;
}