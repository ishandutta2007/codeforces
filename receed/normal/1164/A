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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> a(n), b(m);
	ll ans = 0;
	rep(i, n) {
		cin >> a[i];
		ans += a[i] * m;
	}
	rep(i, m)
		cin >> b[i];
	sort(all(a));
	sort(all(b));
	if (a.back() > b[0]) {
		cout << -1;
		return 0;
	}
	int f = 1;
	rep(i, m) {
		if (b[i] == a.back())
			f = 0;
		ans += b[i] - a.back();
	}
	if (f) {
		if (n == 1) {
			cout << -1;
			return 0;
		}
		else
			ans += a.back() - a[n - 2];
	}
	cout << ans;

}