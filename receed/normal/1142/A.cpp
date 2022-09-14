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

ll n, k, mn = 1e11, mx = -1;

void f(ll d) {
	rep(i, n) {
		ll x = k * i + d;
		ll ca = (x == 0 ? 1 : n * k / __gcd(n * k, k * i + d));
		mn = min(mn, ca);
		mx = max(mx, ca);
	}
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	ll a, b, a1, b1;
	cin >> n >> k >> a >> b;
	f(abs(b - a));
	f((a + b) % k);
	f((2 * k - a - b) % k);
	cout << mn << ' ' << mx << '\n';
}