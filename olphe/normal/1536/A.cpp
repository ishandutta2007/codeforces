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
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	int g = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			g = gcd(g, abs(v[i] - v[j]));
		}
	}
	for (int i = 0; i < N; i++) {
		if (v[i] < 0) {
			cout << "NO\n";
			return;
		}
		g = gcd(g, v[i]);
	}
	auto mx = *max_element(v.begin(), v.end());
	cout << "Yes\n";
	cout << mx / g + 1 << endl << 0;
	for (int i = g; i <= mx; i += g) {
		cout << " " << i;
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