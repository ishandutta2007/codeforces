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
	cin >> N >> M;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	long long int l = v[0], r = v[0];
	for (int i = 1; i < N; i++) {
		long long int nl = v[i];
		long long int nr = v[i] + M - 1;
		nl = max(nl, l - M + 1);
		nr = min(nr, r + M - 1);
		if (nl > nr) {
			cout << "NO\n";
			return;
		}
		l = nl, r = nr;
	}
	if (l > v.back())cout << "NO\n";
	else cout << "YES\n";
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