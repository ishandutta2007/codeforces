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
	cin >> N;
	vector<int>v(N);
	vector<int>w(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i] >> w[i];
	}
	L = 0, R = N + 1;
	while (R - L > 1) {
		int mid = (L + R) / 2;
		int used = 0;
		for (int i = 0; i < N; i++) {
			if (w[i] >= used && v[i] >= mid - used - 1) {
				used++;
			}
		}
		if (used >= mid) {
			L = mid;
		}
		else {
			R = mid;
		}
	}
	cout << L << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}

}