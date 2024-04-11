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
	if (H & 1) {
		if (K < W / 2) {
			cout << "NO\n";
			return;
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
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}