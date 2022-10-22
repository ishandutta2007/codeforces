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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<long long int>v(N);
	for (auto& i : v)cin >> i;
	long long int ans = 0;
	int idx = 0;
	for (int i = 0; i < N; i++) {
		long long int box = -v[i];
		long long int mx = v[i];
		for (int j = i; j >= 0; j--) {
			box += min(mx, v[j]);
			mx = min(mx, v[j]);
		}
		mx = v[i];
		for (int j = i; j < N; j++) {
			box += min(mx, v[j]);
			mx = min(mx, v[j]);
		}
		if (ans < box) {
			ans = box;
			idx = i;
		}
	}
	vector<long long int>ret(N);
	auto i = idx;
	long long int mx = v[i];
	for (int j = i; j >= 0; j--) {
		ret[j] = min(mx, v[j]);
		mx = min(mx, v[j]);
	}
	mx = v[i];
	for (int j = i; j < N; j++) {
		ret[j] = min(mx, v[j]);
		mx = min(mx, v[j]);
	}
	for (auto i : ret)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
//	cin >> T;
	while (T--) {
		Solve();
	}
}