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
	vector<int>w(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	for (int i = N - 2; i >= 0; i--) {
		w[i] = max(w[i], w[i + 1] - v[i + 1] + v[i]);
	}
	for (int i = 1; i < N; i++) {
		if (v[i] - v[i - 1] < w[i]) {
			w[i] = max(w[i], w[i - 1] + v[i] - v[i - 1]);
		}
	}
	long long ans = 1LL * w[0] * (w[0] + 1) / 2;
	for (int i = 1; i < N; i++) {
		if (v[i] - v[i - 1] + w[i - 1] == w[i]) {
			ans += 1LL * (w[i]) * (w[i] + 1) / 2;
			ans -= 1LL * (w[i - 1]) * (w[i - 1] + 1) / 2;
		}
		else {
			ans += 1LL * (w[i]) * (w[i] + 1) / 2;
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}