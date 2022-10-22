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
constexpr double EPS = 1e-12;

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

long long by[3000001];
long long inv[3000001];

long long ncr(long long n, long long r) {
	return by[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void Solve() {
	cin >> N >> M >> K;
	long long ans = 0;
	long long two = 1;
	if (N == M) {
		cout << K * N % MOD << endl;
		return;
	}
	int y = N - M;
	int x = M - 1;
	for (int i = 1; i <= M; i++) {
		long long add = two * i % MOD;
	//	cout << y - 1 << " " << x - i+1 << endl;
		add *= ncr(y - 1 + x - i+1, y - 1);
		add %= MOD;
		ans += add;
		ans %= MOD;
		two *= 2;
		two %= MOD;
	}
	ans *= K;
	ans %= MOD;
	ans *= power(power(2, N - 1, MOD), MOD - 2, MOD);
	ans %= MOD;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	by[0] = inv[0] = 1;
	for (int i = 1; i <= 3000000; i++) {
		by[i] = by[i - 1] * i % MOD;
	}
	inv[3000000] = power(by[3000000], MOD - 2, MOD);
	for (int i = 3000000; i > 0; i--) {
		inv[i - 1] = inv[i] * i % MOD;
	}
	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}