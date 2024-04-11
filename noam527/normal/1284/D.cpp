#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct segtree {
	int type;
	int n;
	vector<int> t;
	segtree() {}
	segtree(const vector<int> &a, int ty) {
		type = ty;
		n = max(2, (int)a.size());
		while (n != (n & -n)) n += (n & -n);
		t.resize(2 * n);
		for (int i = 0; i < a.size(); i++)
			t[i + n - 1] = a[i];
		for (int i = n - 2; i >= 0; i--)
			fix(i);
	}
	void fix(int x) {
		if (type == -1)
			t[x] = min(t[x + x + 1], t[x + x + 2]);
		else
			t[x] = max(t[x + x + 1], t[x + x + 2]);
	}
	void upd(int &x, int v) {
		if (type == -1)
			x = min(x, v);
		else
			x = max(x, v);
	}
	int query(int l, int r) {
		int res = (type == -1 ? md : -md);
		for (l += n - 1, r += n - 1; l < r; l = (l - 1) / 2, r = (r - 1) / 2) {
			if (!(l & 1))
				upd(res, t[l++]);
			if (r & 1)
				upd(res, t[r--]);
		}
		if (l == r)
			upd(res, t[l]);
		return res;
	}
};

int n;
vector<vector<int>> t;

bool check() {
	sort(t.begin(), t.end());

	vector<int> s(n), e(n);
	for (int i = 0; i < n; i++) {
		s[i] = t[i][2];
		e[i] = t[i][3];
	}
	segtree S(s, 1);
	segtree E(e, -1);
	for (int i = 0; i < n; i++) {
		int lo = i, hi = n - 1, mid;
		while (lo < hi) {
			mid = (lo + hi + 1) / 2;
			if (t[mid][0] <= t[i][1]) lo = mid;
			else hi = mid - 1;
		}
		if (i + 1 <= lo) {
			if (S.query(i + 1, lo) > t[i][3] || E.query(i + 1, lo) < t[i][2])
				return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	t.resize(n);
	for (auto &i : t) {
		i.resize(4);
		for (auto &j : i) cin >> j;
	}
	if (!check()) finish("NO");
	for (auto &i : t) {
		swap(i[0], i[2]);
		swap(i[1], i[3]);
	}
	if (!check()) finish("NO");
	finish("YES");
}