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

long long int lcm(long long int a, long long int b) {
	int ret = a * b;
	while (b) {
		a %= b;
		swap(a, b);
	}
	return ret / a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	for (int i = 2; i <= 16; i++) {
		T = lcm(T, i);
	}
	cin >> H >> W;
	vector<vector<int>>v(H, vector<int>(W));
	for (auto &i : v)for (auto &j : i)cin >> j;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if ((i + j) & 1) {
				cout << T + pow(v[i][j], 4);
			}
			else {
				cout << T;
			}
			cout << " ";
		}
		cout << endl;
	}
}