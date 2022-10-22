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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

long long int sum[3001] = {};
long long int v[3001][3001] = {};
long long int num[3001] = {};

long long int func(int l, int r, vector<long long int>dp) {
	long long int ret = 0;
	if (l + 1 == r) {
		for (int i = 0; i <= num[l]; i++) {
			ret = max(ret, dp[K - i] + v[l][i]);
		}
		return ret;
	}
	auto dp1 = dp, dp2 = dp;
	int mid = (l + r) / 2;
	for (int i = l; i < mid; i++) {
		for (int j = K; j >= num[i]; j--) {
			dp2[j] = max(dp2[j], dp2[j - num[i]] + sum[i]);
		}
	}
	for (int i = mid; i < r; i++) {
		for (int j = K; j >= num[i]; j--) {
			dp1[j] = max(dp1[j], dp1[j - num[i]] + sum[i]);
		}
	}
	ret = max(ret, func(mid, r, dp2));
	ret = max(ret, func(l, mid, dp1));
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		for (int j = 0; j < num[i]; j++) {
			cin >> M;
			if (j < K) {
				v[i][j + 1] = M;
				sum[i] += M;
				v[i][j + 1] += v[i][j];
			}
		}
		num[i] = min(num[i], K);
	}
	vector<long long int>dp(K + 1);
	cout << func(0, N, dp) << endl;
}