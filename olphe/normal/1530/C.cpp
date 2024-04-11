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
	cin >> N;
	vector<int>v(N);
	vector<int>w(N);
	for (auto& i : v)cin >> i;
	for (auto& i : w)cin >> i;
	sort(v.rbegin(), v.rend());
	sort(w.rbegin(), w.rend());
	for (int i = 1; i < N; i++) {
		v[i] += v[i - 1];
		w[i] += w[i - 1];
	}
	L = -1, R = N * 100;
	while (R - L > 1) {
		long long mid = (L + R) / 2;
		long long a = 0, b = 0;
		long long use = N + mid - (N + mid) / 4;
		{
			if (mid >= use) {
				a = use * 100;
			}
			else {
				a = mid * 100 + v[use - mid - 1];
			}
		}
		{
			if (use >= N) {
				b = w.back();
			}
			else {
				b = w[use - 1];
			}
		}
		if (a >= b)R = mid;
		else L = mid;
	}
	cout << R << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}