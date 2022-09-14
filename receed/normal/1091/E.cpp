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
 
typedef long long ll;
typedef long double ld;
using namespace std;

const ll MOD = 998244353;

ll n, d = 0;
deque<ll> a, ps, ns;

ll q() {
	ps.assign(n + 2, 0);
	ns.assign(n + 2, 0);
	rep(i, n + 1) {
		int pos = max((ll) i + 1, n + 1 - a[i]);
		ns[pos]++;
		ps[i + 1] += a[i];
		ps[pos] -= a[i];
	}
	rep(i, n + 1) {
		ns[i + 1] += ns[i];
		ps[i + 1] += ps[i];
	}
	ll cs = 0;
	for (ll i = 1; i <= n; i++) {
		cs += a[n + 1 - i];
		if (cs > ps[n + 1 - i] + ns[n + 1 - i] * i + i * (i - 1))
			return n + 1 - i;
	}
	return -1;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	ps.assign(n + 2, 0);
	ns.assign(n + 2, 0);
	rep(i, n) {
		cin >> a[i];
		d = (d + a[i]) % 2;
	}
	sort(a.begin(), a.end());
	vector<ll> ps(n + 2);
	int l = d, r = n - (n - d) % 2 + 1, m;
	while (r - l > 1) {
		m = (l + r) / 2;
		if (m % 2 != d)
			m--;
		int pos = lower_bound(a.begin(), a.end(), m) - a.begin();
		a.insert(a.begin() + pos, m);
		int cr = q();
		if (cr == -1)
			r = m + 1;
		else if (cr <= pos)
			r = m - 1;
		else
			l = m + 2;
		a.erase(a.begin() + pos);
	}
	int pos = lower_bound(a.begin(), a.end(), l) - a.begin();
	a.insert(a.begin() + pos, l);
	if (q() != -1) {
		cout << -1;
		return 0;
	}
	a.erase(a.begin() + pos);
	int nl = d, nr = n - (n - d) % 2 + 1;
	while (nr - nl > 1) {
		m = (nl + nr) / 2;
		if (m % 2 != d)
			m++;
		int pos = lower_bound(a.begin(), a.end(), m) - a.begin();
		a.insert(a.begin() + pos, m);
		int cr = q();
		// cout << nl << ' ' << nr << ' ' << m << "!" << ' ' << cr << endl;
		if (cr == -1)
			nl = m;
		else if (cr <= pos)
			nr = m - 1;
		else
			nl = m + 2;
		a.erase(a.begin() + pos);
	}
	for (int i = l; i <= nl; i += 2)
		cout << i << ' ';
}