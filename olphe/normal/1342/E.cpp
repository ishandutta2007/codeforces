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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

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

	cin >> N >> K;
	vector<long long int>by(N + 1, 1);
	vector<long long int>rev(N + 1, 1);
	for (int i = 2; i <= N; i++) {
		by[i] = by[i - 1] * i%MOD;
		rev[i] = power(by[i], MOD - 2, MOD);
	}
	K = min(K, N);
	K = N - K;
	long long int sum = 0;
	for (int i = 0; i <= K; i++) {
		if ((K-i) & 1) {
			long long int add = by[K] * rev[i] % MOD*rev[K - i] % MOD*power(i, N, MOD) % MOD;
			sum += MOD - add;
			sum %= MOD;
		}
		else {
			long long int add = by[K] * rev[i] % MOD*rev[K - i] % MOD*power(i, N, MOD) % MOD;
			sum += add;
			sum %= MOD;
		}
	}
	sum *= power(by[K], MOD - 2, MOD);
	sum %= MOD;
	K = N - K;
	long long int ans = sum * by[N] % MOD*rev[K] % MOD;
	if (K)ans *= 2;
	ans %= MOD;
	cout << ans << endl;
}