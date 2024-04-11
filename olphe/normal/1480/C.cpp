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

void Solve() {
	cin >> N;
	L = 0, R = N + 1;
	vector<int>v(N + 2);
	v[0] = MOD;
	v[N + 1] = MOD;
	int a = L + (R - L) / 3;
	int b = R - (R - L) / 3;
	while (L + 2 < R) {
		if (!v[a]) {
			cout << "? " << a << endl;
			cin >> v[a];
		}
		if (!v[b]) {
			cout << "? " << b << endl;
			cin >> v[b];
		}
		if (v[a] < v[b]) {
			R = b;
			b = a;
			a = L + (b - L) / 2;
		}
		else {
			L = a;
			a = b;
			b = R - (R - a) / 2;
		}
	}
	cout << "! " << L + 1 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
//	cin >> T;
	while (T--) {
		Solve();
	}
}