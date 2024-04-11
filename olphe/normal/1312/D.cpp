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
constexpr long double EPS = 1e-12;

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

	int N, M;
	cin >> N >> M;
	if (N == 2) {
		cout << 0 << endl;
		return 0;
	}
	long long int ans = 0;
	vector<long long int>by(200001, 1);
	vector<long long int>rev(200001, 1);
	for (int i = 2; i <= 200000; i++) {
		by[i] = by[i - 1] * i%MOD;
		rev[i] = power(by[i], MOD - 2, MOD);
	}
	vector<long long int>two(200001, 1);
	for (int i = 1; i <= 200000; i++) {
		two[i] = two[i - 1] * 2 % MOD;
	}
	for (int i = 1; i < M; i++) {
		long long int add = by[M - 1] * rev[N - 2] % MOD*rev[M - N + 1] % MOD;
		if (i - 1 >= N - 2) {
			long long int minus = by[i - 1] * rev[N - 2] % MOD*rev[i - N + 1] % MOD;
			add += MOD - minus;
			add %= MOD;
		}
		ans += add * two[N - 3] % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
}