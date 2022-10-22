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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	L = -1, R = N;
	while (R - L > 1) {
		int mid = (L + R) / 2;
		bool ok = true;
		K = M;
		int amari = mid;
		for (auto i : v) {
			if (K == 0)ok = false;
			if (K < i) {
				if (amari) {
					amari--;
				}
				else {
					K--;
				}
			}
			else {
			}
		}
		if (ok)R = mid;
		else L = mid;
	}
	for (auto i : v) {
		if (M < i) {
			if (R) {
				R--;
				cout << 0;
			}
			else {
				M--;
				cout << 1;
			}
		}
		else {
			cout << 1;
		}
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}