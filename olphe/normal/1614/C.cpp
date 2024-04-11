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

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x % M;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

void Solve() {
	cin >> N >> K;
	vector<vector<int>>sum(N + 1, vector<int>(30));
	for (int i = 0; i < K; i++) {
		cin >> L >> R >> H;
		L--, R--;
		for (int j = 0; j < 30; j++) {
			if (H >> j & 1)continue;
			sum[L][j]++;
			sum[R + 1][j]--;
		}
	}
	vector<int>v(N);
	long long num = 0;
	for (int i = 0; i < 30; i++) {
		for (int j = 1; j <= N; j++) {
			sum[j][i] += sum[j - 1][i];
		}
		for (int j = 0; j < N; j++) {
			if (!sum[j][i]) {
				v[j] |= 1 << i;
			}
		}
	}
	for (auto i : v)num |= i;
	long long ans = 0;
	for (int i = 0; i < 30; i++) {
		if (num >> i & 1) {
			ans += power(2, N - 1, MOD) * (1LL << i);
			ans %= MOD;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}