#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7, mx = 1e16;
int binpow(int a, int b) {
	if (b == 1) return a;
	if (!b) return 1ll;
	if (b & 1) return a * (binpow(a, b - 1)) % mod;
	int t = binpow(a, b / 2);
	return t * t % mod;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector <int> pr = { 1 };
	while (pr.back() < mx) {
		int need = pr.size() + 1;
		for (int i = 1; i <= 80; ++i) {
			if (pr.back() * i % need == 0) {
				pr.push_back(pr.back() * i);
				break;
			}
		}
	}
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		int ans = 0;
		for (int i = pr.size() - 2; i >= 0; --i) {
			int all = (n / pr[i]) - n / pr[i + 1];
			all %= mod;
			all = (all + mod) % mod;
			ans += (i + 2) * all % mod;
			ans %= mod;
		}
		cout << ans << '\n';
	}
	return 0;
}