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

void Solve() {
	cin >> N;
	vector<long long>v(N);
	for (auto& i : v)cin >> i;
	long long a = 0, b = 0;
	for (int i = 0; i < N; i++) {
		if (i & 1)a = gcd(a, v[i]);
		else b = gcd(b, v[i]);
	}
	int aok = true;
	int bok = true;
	for (int i = 0; i < N; i++) {
		if (i & 1) {
			if (v[i] % b == 0) {
				bok = false;
			}
		}
		else {
			if (v[i] % a == 0) {
				aok = false;
			}
		}
	}
	if (aok) {
		cout << a << endl;
	}
	else if (bok) {
		cout << b << endl;
	}
	else {
		cout << 0 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}