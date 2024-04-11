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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	vector<pair<int, int>>ans;
	cin >> N;
	vector<int>v(N);
	vector<int>w(N);
	for (auto& i : v)cin >> i;
	for (auto& i : w)cin >> i;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (make_pair(v[i], w[i]) > make_pair(v[j], w[j])) {
				ans.push_back({ i,j });
				swap(v[i], v[j]);
				swap(w[i], w[j]);
			}
		}
	}
	for (int i = 1; i < N; i++) {
		if (v[i] < v[i - 1]) {
			cout << -1 << endl;
			return;
		}
		if (w[i] < w[i - 1]) {
			cout << -1 << endl;
			return;
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.first + 1 << " " << i.second + 1 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}