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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<int>ok(N + 1);
	ok[N] = 1;
	for (int i = N - 1; i >= 0; i--) {
		if (i + 1 == v[i])ok[i] = 1;
		else break;
	}
	long double ans = 1;
	if (ok[0])ans = 0;
	for (int i = 0; i < M; i++) {
		cin >> K;
		long double p;
		cin >> p;
		p = 1 - p;
		if (ok[K]) {
			ans *= p;
		}
	}
	ans = 1 - ans;
	cout << fixed << setprecision(20) << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}