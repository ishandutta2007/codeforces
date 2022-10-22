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
	long long ans = 0;
	vector<vector<long long>>v(N * 2, vector<long long>(N * 2));
	for (int i = 0; i < N * 2; i++) {
		for (int j = 0; j < N * 2; j++) {
			cin >> v[i][j];
			if (i >= N && j >= N) {
				ans += v[i][j];
			}
		}
	}
	long long add = LLONG_MAX;
	if (N > 1) {
		for (int i = 0; i < N; i += N - 1) {
			for (int j = 0; j < N; j += N - 1) {
				add = min(add, v[i + N][j]);
				add = min(add, v[i][j + N]);
			}
		}
	}
	else {
		add = min(v[0][1], v[1][0]);
	}
	cout << ans + add << endl;
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