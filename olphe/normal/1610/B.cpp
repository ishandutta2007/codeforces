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

vector<int>func(vector<int>v, int num) {
	vector<int>ret;
	for (auto i : v) {
		if (i != num)ret.push_back(i);
	}
	return ret;
}

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	auto w = v;
	reverse(w.begin(), w.end());
	for (int i = 0; i < N; i++) {
		if (v[i] != w[i]) {
			if (func(v, v[i]) == func(w, v[i])) {
				cout << "Yes\n";
				return;
			}
			if (func(v, w[i]) == func(w, w[i])) {
				cout << "Yes\n";
				return;
			}
			break;
		}
		if (i + 1 == N) {
			cout << "Yes\n";
			return;
		}
	}
	cout << "No\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}

}