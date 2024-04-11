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
	cin >> N >> K;
	int one = 0;
	vector<int>v(N);
	int er = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		one += v[i];
		if (i && v[i - 1] == v[i]) {
			er++;
		}
	}
	if (!one) {
		cout << "NO" << endl;
		return;
	}
	if (K == 2) {
		cout << "YES" << endl;
		return;
	}
	for (int i = 0; i <= er + one - 1; i++) {
		if (N - i >= 1 && (N - i) % (K - 1) == 1) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}