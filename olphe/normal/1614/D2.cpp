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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

constexpr int MAX = 20000000;
int sum[MAX + 1];
long long dp[MAX + 1];
int num[MAX + 1];

void Solve() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		num[K] ++;
	}
	for (int i = 1; i <= MAX; i++) {
		for (int j = i; j <= MAX; j += i) {
			sum[i] += num[j];
		}
		if (sum[i] == N) {
			dp[i] = N * i;
		}
	}
	dp[1] = N;
	for (int i = 1; i <= MAX; i++) {
		if (dp[i] == 0)continue;
		for (int j = i * 2; j <= MAX; j += i) {
			if (sum[j]) {
				dp[j] = max(dp[j], dp[i] + 1LL * sum[j] * (j - i));
			}
		}
	}
	cout << *max_element(dp, dp + MAX + 1) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
//	cin >> T;
	while (T--) {
		Solve();
	}
}