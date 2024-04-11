#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int N = 200003, MOD = 998244353;
int a[N];

ll pw(ll x, ll p) {
	ll ans = 1;
	for (int i = 30; i >= 0; i--) {
		ans = ans * ans % MOD;
		if (p & (1 << i))
			ans = ans * x % MOD;
	}
	return ans;
}

ll n, k;

ll f(ll d, ll x1, ll x2) {
	if (x1 == 0 && x2 == 0)
		return pw(k - 1, d - 1) * k % MOD;
	if (x1 == 0 || x2 == 0)
		return pw(k - 1, d);
	ll c1 = 0, c2 = 0, n2;
	if (x1 == x2)
		c1 = 1;
	else
		c2 = 1;
	rep(i, d) {
		n2 = (c1 * (k - 1) + c2 * (k - 2)) % MOD;
		c1 = c2;
		c2 = n2;		
	}
	return n2;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	rep(i, n) {
		cin >> a[i];
		if (i > 1 && a[i] == a[i - 2] && a[i] != -1) {
			cout << 0;
			return 0;
		}
	}
	ll ans = 1;
	rep(t, 2) {
		int l = 0, x = 0;
		for (int j = t; j < n + 2; j += 2) {
			if (a[j] != -1) {
				if (x > 0)
					ans = ans * f(x, l, a[j]) % MOD;
				l = a[j];
				x = 0;
			}
			else
				x++;
		}
	}
	cout << ans;
}