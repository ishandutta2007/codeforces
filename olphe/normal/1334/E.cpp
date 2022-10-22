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

long long int gcd(long long int a, long long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

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

	cin >> K;
	vector<long long int>box;
	for (long long int i = 2; i*i <= K; i++) {
		if (K%i == 0) {
			box.push_back(i);
			while (K%i == 0)K /= i;
		}
	}
	if (K > 1) {
		box.push_back(K);
	}
	vector<long long int>by(101, 1);
	vector<long long int>rev(101, 1);
	for (int i = 1; i <= 100; i++) {
		by[i] = by[i - 1] * i%MOD;
		rev[i] = power(by[i], MOD - 2, MOD);
	}
	cin >> K;
	while (K--) {
		cin >> N >> M;
		L = gcd(N, M);
		long long int ans = 1;
		long long int num = N / L;
		int sum = 0;
		for (auto i : box) {
			long long int c = 0;
			while (num%i == 0) {
				num /= i;
				c++;
				sum++;
			}
			ans *= rev[c];
			ans %= MOD;
		}
		ans *= by[sum];
		ans %= MOD;
		num = M / L;
		sum = 0;
		for (auto i : box) {
			long long int c = 0;
			while (num%i == 0) {
				num /= i;
				c++;
				sum++;
			}
			ans *= rev[c];
			ans %= MOD;
		}
		ans *= by[sum];
		ans %= MOD;
		cout << ans << endl;
	}
}