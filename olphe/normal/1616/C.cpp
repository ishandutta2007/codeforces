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
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	if (N <= 2) {
		cout << 0 << endl;
		return;
	}
	int ans = N;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int dif = N - 2;
			int x = j - i;
			int y = v[j] - v[i];
			for (int k = 0; k < N; k++) {
				if (i == k)continue;
				if (j == k)continue;
				if (y * (k - i) + x * v[i] == x * v[k]) {
					dif--;
				}
			}
			ans = min(ans, dif);
		}
	}
	cout << ans << endl;
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