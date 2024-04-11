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
	vector<vector<int>>v(N, vector<int>(N));
	int len = N;
	while (len > 0) {
		int x = 0, y = 0, num = 0;
		int dx = 0, dy = 1;
		do {
			if (num < 2) {
				v[y+(N-len)/2][x+(N-len)/2] = 1;
			}
			num++;
			num %= 4;
			x += dx;
			y += dy;
			if (dy == 1 && y + 1 == len) {
				dx = 1, dy = 0;
			}
			if (dx == 1 && x + 1 == len) {
				dx = 0, dy = -1;
			}
			if (dy == -1 && y == 0) {
				dx = -1; dy = 0;
			}
			if (dx == -1 && x == 0) {
				dx = 0, dy = 1;
			}
		} while (x || y);
		len -= 4;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> K;
			if (v[i][j]) {
				ans ^= K;
			}
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