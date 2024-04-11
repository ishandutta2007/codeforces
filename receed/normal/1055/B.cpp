#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	ll l, d;
	cin >> n >> m >> l;
	vector<ll> a(n + 2, 0);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > l && a[i - 1] <= l)
			ans++;
	}
	ll t, p;
	for (int i = 0; i < m; i++) {
		cin >> t;
		if (t == 0)
			cout << ans << '\n';
		else {
			cin >> p >> d;
			a[p] += d;
			if (a[p] <= l || a[p] - d > l)
				continue;
			if (a[p - 1] <= l && a[p + 1] <= l)
				ans++;
			else if (a[p - 1] > l && a[p + 1] > l)
				ans--;
		}
	}
}