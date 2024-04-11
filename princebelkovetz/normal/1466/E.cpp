#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cassert>
#include <map>
#include <set>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
const int bb = 62, mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	while (testcases-- > 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) {
			cin >> x;
		}
		vector <int> bits(bb);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < bb; ++j) {
				bits[j] += ((a[i] >> j) & 1);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int s1 = 0, s2 = ((a[i] % mod) * n) % mod;
			s1 %= mod, s2 %= mod;
			vector <int> cur;
			for (int j = 0; j < bb; ++j) {
				cur.push_back((a[i] >> j) & 1);
			}
			for (int j = 0; j < bb; ++j) {
				if (!cur[j]) {
					s2 = (s2 + ((bits[j] * ((1ll << j) % mod)) % mod)) % mod;
				}
				else {
					s1 = (s1 + ((bits[j] * ((1ll << j) % mod)) % mod)) % mod;
				}
				s2 %= mod, s1 %= mod;
			}
			int get = (s1 * s2) % mod;
			ans += get, ans %= mod;
		}
		cout << ans % mod << '\n';
	}
}