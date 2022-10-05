#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct segtree {
	int n;
	vector<int> sum, pref;
	segtree() {}
	segtree(int sz) {
		n = max(2, sz);
		while (n != (n & -n)) n += (n & -n);
		sum.resize(2 * n);
		pref.resize(2 * n);
		for (int i = 0; i < n; i++)
			sum[i + n - 1] = -1, pref[i + n - 1] = 0;
		for (int i = n - 2; i >= 0; i--) fix(i);
	}
	void fix(int x) {
		sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
		pref[x] = max(pref[2 * x + 1], sum[2 * x + 1] + pref[2 * x + 2]);
	}
	void upd(int pos, int add) {
		pos += n - 1;
		sum[pos] += add;
		pref[pos] = max(0, sum[pos]);
		pos = (pos - 1) / 2;
		while (pos) {
			fix(pos);
			pos = (pos - 1) / 2;
		}
		fix(0);
	}
	void insert(int val) {
		if (val == -1) upd(0, 2);
		else upd(val, 1);
	}
	void erase(int val) {
		if (val == -1) upd(0, -2);
		else upd(val, -1);
	}
	bool good() {
		return pref[0] <= 0;
	}
};

int n, m, h;
vector<int> a, b;

int bs(int val) {
	val = h - val;
	int lo = 0, hi = m - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (b[mid] < val) lo = mid + 1;
		else hi = mid;
	}
	if (b[lo] < val) lo++;
	return m - 1 - lo;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> h;
	a.resize(n);
	b.resize(m);
	for (auto &i : b) cin >> i;
	for (auto &i : a) cin >> i;
	sort(b.begin(), b.end());
	for (auto &i : a) i = bs(i);

	int ans = 0;
	segtree T(m);
	for (int i = 0; i < m; i++)
		T.insert(a[i]);
	if (T.good()) ans++;
	for (int i = m; i < n; i++) {
		T.insert(a[i]);
		T.erase(a[i - m]);
		if (T.good()) ans++;
	}
	cout << ans << endl;
}