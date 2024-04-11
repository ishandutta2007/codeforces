#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct dsu {
	int n;
	vector<int> p, r, s;
	dsu() {}
	dsu(int sz) {
		n = sz;
		p.resize(n);
		r.resize(n);
		s.resize(n);
		clear();
	}
	void clear() {
		for (int i = 0; i < n; i++) {
			p[i] = i;
			r[i] = 0;
			s[i] = 1;
		}
	}
	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (r[x] < r[y]) {
			p[x] = y;
			s[y] += s[x];
		}
		else {
			p[y] = x;
			s[x] += s[y];
			if (r[x] == r[y]) r[x]++;
		}
		return true;
	}
	int query() {
		return s[find(0)];
	}
};

int n, k;
vector<int> a;
dsu D;

vector<vector<int>> all;
int to[122][122];

int find(const vector<int> &A) {
	return lower_bound(all.begin(), all.end(), A) - all.begin();
}

vector<int> apply(const vector<int> &on, const vector<int> &trans) {
	vector<int> rtn(k);
	for (int i = 0; i < k; i++)
		rtn[i] = on[trans[i]];
	return rtn;
}


void work(int v) {
	if (D.find(0) == D.find(to[0][v])) return;
	for (int i = 0; i < all.size(); i++)
		D.unite(i, to[i][v]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	vector<int> perm(k);
	for (int i = 0; i < k; i++) perm[i] = i;
	do {
		all.push_back(perm);
	} while (next_permutation(perm.begin(), perm.end()));

	for (int i = 0; i < all.size(); i++) for (int j = 0; j < all.size(); j++)
		to[i][j] = find(apply(all[i], all[j]));

	if (OO) cout << "here\n";

	a.resize(n);
	for (int i = 0; i < n; i++) {
		vector<int> tmp(k);
		for (auto &j : tmp) cin >> j, --j;
		a[i] = find(tmp);
	}

	D = dsu(all.size());

	vector<int> lst(all.size(), -1);
	vector<pair<int, int>> ord;

	ll ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		D.clear();
		if (OO) cout << "entering index " << i << '\n';
		if (lst[a[i]] != -1) {
			ord.erase(find(ord.begin(), ord.end(), make_pair(a[i], lst[a[i]])));
		}
		lst[a[i]] = i;
		ord.emplace_back(a[i], i);
		if (OO) {
			cout << "ord\n";
			for (const auto &j : ord) cout << j.first << " " << j.second << '\n';
		}
		int lstind = i;
		for (int j = (int)ord.size() - 1; j >= 0; j--) {
			ans += ll(ord[j].second - lstind) * D.query();
			lstind = ord[j].second;
			work(ord[j].first);
		}
		ans += ll(n - lstind) * D.query();
	}
	cout << ans << '\n';
}