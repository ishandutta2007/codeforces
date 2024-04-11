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
	for (auto& i : v)cin >> i;
	if (N == 3 && (v[1] & 1)) {
		cout << -1 << endl;
		return;
	}
	long long sum = accumulate(v.begin(), v.end(), 0LL) - v.front() - v.back();
	if (sum == 0) {
		cout << 0 << endl;
		return;
	}
	bool one = true;
	int add = 0;
	for (int i = 1; i + 1 < N; i++) {
		if (v[i] > 1) {
			one = false;
		}
		if (v[i] & 1) {
			add++;
		}
	}
	if (one) {
		cout << -1 << endl;
		return;
	}
	cout << (sum + add) / 2 << endl;
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