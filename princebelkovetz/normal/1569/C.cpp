#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 998244353, N = 5e5 + 3;

vector <int> fct(N), rfct(N);

int binpow(int a, int b) {
	if (!b) return 1;
	if (b & 1) return a * binpow(a, b - 1) % mod;
	int t = binpow(a, b / 2);
	return t * t % mod;
}
int C(int n, int k) {
	if (k > n or k < 0) return 0;
	int res = fct[n] * rfct[k] % mod;
	return res * rfct[n - k] % mod;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fct[0] = rfct[0] = 1;
	for (int i = 1; i < N; ++i) {
		fct[i] = fct[i - 1] * i % mod;
		rfct[i] = binpow(fct[i], mod - 2);
	}

	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		sort(a.begin(), a.end());
		if (a[n - 1] >= a[n - 2] + 2) {
			cout << "0\n";
		}
		else if (a[n - 1] == a[n - 2]) {
			cout << fct[n] << '\n';
		}
		else {
			int cnt = 1;
			for (int i = 0; i < n; ++i)
				cnt += (a[i] == a[n - 2]);

			cout << C(n, cnt) * (cnt - 1) % mod * fct[cnt - 1] % mod * fct[n - cnt]  % mod << '\n';
		}
	}

	return 0;
}