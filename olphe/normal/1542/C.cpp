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
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

vector<int>box;

void Solve() {
	cin >> N;
	long long by = 1;
	long long ans = 0;
	long long bef = 0;
	for (auto i : box) {
		long long num = N / by;
		by = lcm(by, i);
		num -= N / by;
		ans += num % MOD * i;
		ans %= MOD;
		bef = i;
	}
	cout << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long l = 1;
	for (int i = 1; i <= 50; i++) {
		auto nx = lcm(l, i);
		if (l == nx)continue;
		l = nx;
		box.push_back(i);
		if (l > 1e16)break;
	}
	cin >> T;
	while (T--) {
		Solve();
	}

}