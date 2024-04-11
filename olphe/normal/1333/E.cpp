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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	if (N == 3) {
		cout << "8 3 9" << endl;
		cout << "2 1 4" << endl;
		cout << "6 7 5" << endl;
		return 0;
	}
	if (N < 4) {
		cout << -1 << endl;
		return 0;
	}
	vector<vector<int>>v(N, vector<int>(N));
	v[0][0] = 4, v[0][1] = 3, v[0][2] = 6, v[0][3] = 12, v[1][0] = 7, v[1][1] = 5, v[1][2] = 9, v[1][3] = 15, v[2][0] = 14, v[2][1] = 1, v[2][2] = 11, v[2][3] = 10, v[3][0] = 13, v[3][1] = 8, v[3][2] = 16, v[3][3] = 2;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			v[i][j] += N * N - 16;
		}
	}
	if (N == 4) {
		for (auto i : v) {
			for (auto j : i)cout << j << " ";
			cout << endl;
		}
		return 0;
	}
	int num = N * N - 16;
	v[2][4] = num--;
	v[1][4] = num--;
	v[0][4] = num--;
	v[3][4] = num--;
	v[4][4] = num--;
	v[4][3] = num--;
	v[4][2] = num--;
	v[4][1] = num--;
	v[4][0] = num--;
	for (int i = 5; i < N; i++) {
		if (i & 1) {
			for (int j = 0; j <= i; j++) {
				v[i][j] = num--;
			}
			for (int j = i - 1; j >= 0; j--) {
				v[j][i] = num--;
			}
		}
		else {
			for (int j = 0; j <= i; j++) {
				v[j][i] = num--;
			}
			for (int j = i - 1; j >= 0; j--) {
				v[i][j] = num--;
			}
		}
	}
	for (auto i : v) {
		for (auto j : i)cout << j << " ";
		cout << endl;
	}
}