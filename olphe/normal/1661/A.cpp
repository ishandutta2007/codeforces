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
	vector<int>a(N);
	vector<int>b(N);
	for (auto& i : a)cin >> i;
	for (auto& i : b)cin >> i;
	for (int i = 0; i < N; i++) {
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
		}
	}
	long long ans = 0;
	for (int i = 1; i < N; i++) {
		ans += abs(a[i] - a[i - 1]);
		ans += abs(b[i] - b[i - 1]);
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