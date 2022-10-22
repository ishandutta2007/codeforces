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
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<long long int>x(N);
	vector<long long int>y(N);
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	if (N & 1) {
		cout << 1 << endl;
	}
	else {
		cout << (x[N / 2] - x[N / 2 - 1] + 1) * (y[N / 2] - y[N / 2 - 1] + 1) << endl;
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