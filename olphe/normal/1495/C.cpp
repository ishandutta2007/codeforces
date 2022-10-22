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
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> H >> W;
	vector<string>s(H);
	for (auto &i : s)cin >> i;
	if (W %3) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j += 3) {
				s[i][j] = 'X';
			}
		}
		for (int j = 1; j < W; j+=3) {
			bool flag = false;
			for (int i = 0; i < H; i++) {
				if (s[i][j] == 'X') {
					flag = true;
					if (j + 1 < W) {
						s[i][j + 1] = 'X';
						break;
					}
				}
			}
			if (!flag&&j + 1 < W) {
				for (int i = 0; i < H; i++) {
					if (s[i][j + 1] == 'X') {
						flag = true;
						if (j + 1 < W) {
							s[i][j] = 'X';
							break;
						}
					}
				}
			}
			if (!flag) {
				s[0][j] = 'X';
				if (j + 1 < W) {
					s[0][j + 1] = 'X';
				}
			}
		}
	}
	else {
		for (int i = 0; i < H; i++) {
			for (int j = 1; j < W; j += 3) {
				s[i][j] = 'X';
			}
		}
		for (int j = 2; j < W; j += 3) {
			bool flag = false;
			for (int i = 0; i < H; i++) {
				if (s[i][j] == 'X') {
					flag = true;
					if (j + 1 < W) {
						s[i][j + 1] = 'X';
						break;
					}
				}
			}
			if (!flag&&j + 1 < W) {
				for (int i = 0; i < H; i++) {
					if (s[i][j + 1] == 'X') {
						flag = true;
						if (j + 1 < W) {
							s[i][j] = 'X';
							break;
						}
					}
				}
			}
			if (!flag) {
				s[0][j] = 'X';
				if (j + 1 < W) {
					s[0][j + 1] = 'X';
				}
			}
		}
	}
	for (auto i : s)cout << i << endl;
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