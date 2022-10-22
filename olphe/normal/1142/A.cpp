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

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

long long int gcd(long long int a, long long int b) {
	if (!a || !b)return a + b;
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	cin >> L >> R;

	long long int a = MOD * MOD;
	long long int b = 0;
	for (int i = 0; i < N; i++) {
		long long int c = abs(R + i * K - L);
		long long int g = gcd(c, N*K);
		a = min(a, N*K / g);
		b = max(b, N*K / g);
	}
	for (int i = 0; i < N; i++) {
		long long int c = abs(R + i * K + L);
		long long int g = gcd(c, N*K);
		a = min(a, N*K / g);
		b = max(b, N*K / g);
	}
	for (int i = 0; i < N; i++) {
		long long int c = abs(-R + i * K - L);
		long long int g = gcd(c, N*K);
		a = min(a, N*K / g);
		b = max(b, N*K / g);
	}
	for (int i = 0; i < N; i++) {
		long long int c = abs(-R + i * K + L);
		long long int g = gcd(c, N*K);
		a = min(a, N*K / g);
		b = max(b, N*K / g);
	}
	cout << a << " " << b << endl;
	return 0;
}