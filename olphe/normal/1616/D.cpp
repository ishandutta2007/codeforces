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
	vector<long long>v(N);
	for (auto& i : v)cin >> i;
	long long x;
	cin >> x;
	for (auto& i : v)i -= x;
	long long ans = 0;
	long long sum = 0;
	long long mx = LLONG_MIN / 10;
	for (auto i : v) {
		if (mx > sum + i) {
			mx = LLONG_MIN / 10;
			sum = 0;
		}
		else {
			ans++;
			mx = max(mx, sum);
			sum += i;
		}
	}
	cout << ans << endl;
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