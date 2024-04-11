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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<string>s(N);
	for (auto &i : s)cin >> i;
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		int num = 0;
		for (int h = 0; h < N; h++) {
			for (int w = 0; w < N; w++) {
				sum += s[h][w] == 'X';
				num += s[h][w] == 'X' && (h + w) % 3 == i;
			}
		}
		if (num * 3 <= sum) {
			for (int h = 0; h < N; h++) {
				for (int w = 0; w < N; w++) {
					if (s[h][w] == 'X' && (h + w) % 3 == i) {
						s[h][w] = 'O';
					}
				}
			}
			for (auto i : s)cout << i << endl;
			return;
		}
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