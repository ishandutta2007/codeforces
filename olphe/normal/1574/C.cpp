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
	vector<long long>v(N);
	for (auto& i : v)cin >> i;
	sort(v.begin(), v.end());
	cin >> K;
	long long sum = accumulate(v.begin(), v.end(), 0LL);
	while (K--) {
		cin >> R >> L;
		auto it = lower_bound(v.begin(), v.end(), R);
		long long ans = 1LL << 60;
		if (it == v.end()) {
			ans = min(ans, R - *prev(it) + max(0LL, L - (sum - *prev(it))));
		}
		else {
			ans = min(ans, max(0LL, L - (sum - *it)));
			if (it != v.begin()) {
				ans = min(ans, R - *prev(it) + max(0LL, L - (sum - *prev(it))));
			}
		}
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}