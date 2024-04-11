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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> H >> W;
		vector<vector<int>>v(H,vector<int>(W));
		for (auto &i : v) {
			for (auto &j : i)cin >> j;
		}
		vector<vector<int>>w(H, vector<int>(W));
		for (int i = 1; i < H - 1; i++) {
			for (int j = 1; j < W - 1; j++) {
				w[i][j] = 4;
			}
		}
		for (int i = 0; i < H; i++) {
			w[i][0] = w[i].back() = 3;
		}
		for (int j = 0; j < W; j++) {
			w[0][j] = w.back()[j] = 3;
		}
		w[0][0] = w[0].back() = w.back()[0] = w.back().back() = 2;
		bool flag = true;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (v[i][j] > w[i][j])flag = false;
			}
		}
		if (flag) {
			cout << "YES\n";
			for (auto i : w) {
				for (auto j : i)cout << j << " ";
				cout << endl;
			}
		}
		else {
			cout << "NO\n";
		}
	}

}