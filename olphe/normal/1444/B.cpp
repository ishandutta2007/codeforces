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

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N*2);
	for (auto &i : v)cin >> i;
	sort(v.begin(), v.end());
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		ans -= v[i];
	}
	for (int i = N; i < 2 * N; i++) {
		ans += v[i];
	}
	ans %= MOD;
	vector<long long int>by(2 * N + 1, 1);
	for (int i = 2; i <= 2 * N; i++) {
		by[i] = by[i - 1] * i%MOD;
	}
	ans *= by[2 * N];
	ans %= MOD;
	ans *= power(power(by[N], MOD - 2, MOD), 2, MOD);
	cout << ans % MOD << endl;
}