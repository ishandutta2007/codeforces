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
	string s;
	cin >> s;
	if (K == 0) {
		cout << 1 << endl;
		return;
	}
	vector<long long>by(N + 1, 1);
	vector<long long>inv(N + 1, 1);
	for (int i = 1; i <= N; i++) {
		by[i] = by[i - 1] * i % MOD;
		inv[i] = power(by[i], MOD - 2, MOD);
	}
	vector<int>box;
	box.push_back(-1);
	for (int i = 0; i < N; i++) {
		if (s[i] == '1') {
			box.push_back(i);
		}
	}
	box.push_back(N);
	long long ans = 0;
	if (K + 1 >= box.size())ans = 1;
	for (int i = 0; i + K + 1 < box.size(); i++) {
		L = box[i] + 1;
		R = box[i + K + 1] - 1;
		long long add = by[R - L + 1] * inv[K] % MOD * inv[R - L + 1 - K] % MOD;
		ans += add;
		if (i) {
			R = box[i + K] - 1;
			add = by[R - L + 1] * inv[K - 1] % MOD * inv[R - L + 1 - K + 1] % MOD;
			add = MOD - add;
			ans += add;
		}
		ans %= MOD;
	}
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}