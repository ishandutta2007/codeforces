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
	cin >> H >> W >> K;
	if ((H * W) & 1) {
		cout << "NO\n";
		return;
	}
	vector<vector<char>>ans(H, vector<char>(W));
	if (H & 1) {
		if (K < W / 2) {
			cout << "NO\n";
			return;
		}
		for (int i = 0; i < W; i += 2) {
			if (i % 4)ans.back()[i] = ans.back()[i + 1] = 'y';
			else ans.back()[i] = ans.back()[i + 1] = 'z';
		}
		K -= W / 2;
		H--;
	}
	if (W & 1) {
		if (H * (W - 1) < K * 2) {
			cout << "NO\n";
			return;
		}
	}
	if (K & 1) {
		cout << "NO\n";
		return;
	}
	for (int w = 0; w + 1 < W; w += 2) {
		for (int h = 0; h < H; h++) {
			if (K) {
				set<char>c;
				ans[h][w] = 'a';
				if (h) {
					c.insert(ans[h - 1][w]);
					c.insert(ans[h - 1][w + 1]);
				}
				if (w) {
					c.insert(ans[h][w - 1]);
				}
				for (auto i : c) {
					if (ans[h][w] == i)ans[h][w]++;
				}
				ans[h][w + 1] = ans[h][w];
				K--;
			}
		}
	}
	for (int h = 0; h < H; h++) {
		for (int w = 0; w < W; w++) {
			if (ans[h][w] == 0) {
				set<char>c;
				ans[h][w] = 'a';
				if (h) {
					c.insert(ans[h - 1][w]);
				}
				if (w) {
					c.insert(ans[h][w - 1]);
					c.insert(ans[h + 1][w - 1]);
				}
				for (auto i : c) {
					if (ans[h][w] == i)ans[h][w]++;
				}
				ans[h + 1][w] = ans[h][w];
			}
		}
	}
	cout << "YES\n";
	for (auto i : ans) {
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