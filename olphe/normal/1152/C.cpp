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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

long long int gcd(long long int a, long long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	if (N == M) {
		cout << 0 << endl;
		return 0;
	}
	K = abs(N - M);
	int ans = MOD;
	long long int p = MOD * MOD;
	for (int i = 0; i <= 100000; i++) {
		long long int box = (N + i)*(M + i) / gcd(N + i, M + i);
		if (box < p) {
			p = box;
			ans = i;
		}
		if (box == p && i < ans)ans = i;
	}
	for (int i = 1; i*i <= K; i++) {
		if (K%i)continue;
		int j = i - (N%i);
		long long int box = (N + j)*(M + j) / gcd(N + j, M + j);
		if (box < p) {
			p = box;
			ans = j;
		}
		if (box == p && j < ans)ans = j;
		i = K / i;
		j = i - (N%i);
		box = (N + j)*(M + j) / gcd(N + j, M + j);
		if (box < p) {
			p = box;
			ans = j;
		}
		if (box == p && j < ans)ans = j;
		i = K / i;
	}
	cout << ans << endl;
	return 0;
}