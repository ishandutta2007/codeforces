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
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int ok[44444];

void Solve() {
	cin >> N;
	K = N * 2 - 1;
	K = sqrt(K);
	cout << (K-1)/2 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	for (long long int i = 3; i < 44444; i++) {
		long long int a = i * i / 2;
		long long int b = a + 1;
		ok[i] += ok[i - 1];
		if (b == i * i - a || b == a * a - i) {
			ok[i]++;
		}
	}
	while (T--) {
		Solve();
	}
}