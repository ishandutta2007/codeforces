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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	vector<long long int>v(N);
	vector<long long int>w(M);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	sort(v.begin(), v.end());
	long long int box = 0;
	for (auto i : v) {
		box += w[i - 1];
	}
	long long int ans = box;
	for (int i = 0; i < min(N, M); i++) {
		box += w[i];
		box -= w[v[v.size() - 1 - i] - 1];
		ans = min(ans, box);
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}