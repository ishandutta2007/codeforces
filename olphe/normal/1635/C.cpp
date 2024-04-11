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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	if (v[N - 2] > v[N - 1]) {
		cout << -1 << endl;
		return;
	}
	if (v.back() >= 0) {
		cout << N - 2 << endl;
		for (int i = N - 2; i > 0; i--) {
			cout << i << " " << i + 1 << " " << N << endl;
		}
		return;
	}
	for (int i = 1; i < N; i++) {
		if (v[i] < v[i - 1]) {
			cout << -1 << endl;
			return;
		}
	}
	cout << 0 << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}