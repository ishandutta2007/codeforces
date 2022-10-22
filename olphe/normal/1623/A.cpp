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
	cin >> H >> W;
	int sy, sx, gy, gx;
	cin >> sy >> sx >> gy >> gx;
	int ans = 100000;
	if (sy <= gy) {
		ans = min(ans, gy - sy);
	}
	else {
		ans = min(ans, (int)H * 2 - sy - gy);
	}
	if (sx <= gx) {
		ans = min(ans, gx - sx);
	}
	else {
		ans = min(ans, (int)W * 2 - sx - gx);
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