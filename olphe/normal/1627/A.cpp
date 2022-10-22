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
	cin >> H >> W;
	int y, x;
	cin >> y >> x;
	y--, x--;
	vector<string>s(H);
	for (auto& i : s)cin >> i;
	int ans = 3;
	for (int i = 0; i < H; i++) {
		if (s[i][x] == 'B')ans = min(ans, 1);
	}
	for (int i = 0; i < W; i++) {
		if (s[y][i] == 'B')ans = min(ans, 1);
	}
	if (s[y][x] == 'B')ans = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (s[i][j] == 'B') {
				ans = min(ans, 2);
			}
		}
	}
	if (ans == 3)ans = -1;
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