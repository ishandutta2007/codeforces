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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> H >> W;
	vector<vector<int>>v(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i && i + 1 != H&&j && j + 1 != W)continue;
			bool ok = true;
			if (j) {
				if (v[i][j - 1])ok = false;
			}
			if (i) {
				if (j) {
					if (v[i - 1][j - 1])ok = false;
				}
				if (v[i - 1][j])ok = false;
				if (j + 1 < W) {
					if (v[i - 1][j + 1])ok = false;
				}
			}
			if (ok) {
				v[i][j] = 1;
			}
		}
	}
	for (auto i : v) {
		for (auto j : i)cout << j;
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}