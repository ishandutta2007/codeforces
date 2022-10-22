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

long long ans(vector<int>v, int mx) {
	long long ans = 0;
	int odd = 0;
	long long amari = 0;
	for (auto i : v) {
		int dif = mx - i;
		if (dif & 1) {
			odd++;
			dif--;
		}
		amari += dif;
	}
	if (odd) {
		amari -= min(amari, max(0LL, odd * 2LL - 2));
		ans += odd * 2 - 1;
		if (amari) {
			ans++;
			if (amari >= 2) {
				amari -= 2;
			}
		}
	}
	if (amari % 3 == 2)amari++;
	ans += (amari / 3) * 2;
	amari %= 3;
	if (amari)ans++;
	return ans;
}

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	cout << min(ans(v, *max_element(v.begin(), v.end())), ans(v, *max_element(v.begin(), v.end()) + 1)) << endl;
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