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

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	vector<int>w(N);
	for (auto& i : w)cin >> i;
	long long ans = 0;
	vector<vector<int>>dp(N + 1, vector<int>(10001, -1));
	dp[0][0] = 0;
	for (int i = 0; i < N; i++) {
		ans += v[i] * v[i] * (N - 1);
		ans += w[i] * w[i] * (N - 1);
		for (int j = 0; j <= 10000; j++) {
			if (dp[i][j] == -1)continue;
			dp[i + 1][j + v[i]] = j;
			dp[i + 1][j + w[i]] = j;
		}
	}
	int sum = accumulate(v.begin(), v.end(), 0) + accumulate(w.begin(), w.end(), 0);
	for (int i = sum / 2; i <= sum; i++) {
		if (dp[N][i] != -1) {
			int c = i;
			for (int j = N; j > 0; j--) {
				int num = c - dp[j][c];
				if (v[j - 1] == num) {
					ans += (i - v[j - 1]) * v[j - 1];
					ans += (sum - i - w[j - 1]) * w[j - 1];
				}
				else {
					ans += (sum - i - v[j - 1]) * v[j - 1];
					ans += (i - w[j - 1]) * w[j - 1];
				}
				c -= num;
			}
			break;
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