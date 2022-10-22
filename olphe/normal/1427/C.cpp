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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> N;
	vector<int>dp(N + 1, -MOD);
	vector<int>t(N + 1);
	vector<int>x(N + 1, 1);
	vector<int>y(N + 1, 1);
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> x[i] >> y[i];
	}
	int num = -MOD;
	for (int i = 1; i <= N; i++) {
		if (i > 1000) {
			num = max(num, dp[i - 1001]);
		}
		for (int j = max(i - 1000, 0); j < i; j++) {
			if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		dp[i] = max(dp[i], num + 1);
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}