#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
//#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-4, pi = acos(-1);
using namespace std;

bool isgood(vector<pair<int, int>> &a, int l, int r) {
	int lo = 0, hi = (int)a.size() - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (l <= a[mid].first) hi = mid;
		else lo = mid + 1;
	}
	if (l > a[lo].first) return false;
	return a[lo].second <= r;
}

struct segtree {
	int n;
	vector<pair<int, int>> tree[1 << 18];
	segtree(vector<vector<pair<int, int>>> &a) {
		n = max(2, (int)a.size());
		while (n != (n & -n)) n += (n & -n);
		for (int i = 0; i < a.size(); i++)
			tree[i + n - 1] = a[i];
		for (int i = n - 2; i >= 0; i--)
			tree[i] = fix(tree[2 * i + 1], tree[2 * i + 2]);
	}
	vector<pair<int, int>> fix(vector<pair<int, int>> &a, vector<pair<int, int>> &b) {
		vector<pair<int, int>> rtn;
		int p1 = 0, p2 = 0;
		while (p1 < a.size() && p2 < b.size()) {
			if (a[p1].first < b[p2].first) {
				rtn.emplace_back(a[p1].first, max(a[p1].second, b[p2].second));
				p1++;
			}
			else if (a[p1].first > b[p2].first) {
				rtn.emplace_back(b[p2].first, max(a[p1].second, b[p2].second));
				p2++;
			}
			else {
				rtn.emplace_back(a[p1].first, max(a[p1].second, b[p2].second));
				p1++;
				p2++;
			}
		}
		return rtn;
	}
	bool query(int a, int b, int l, int r) {
		return query(a, b, l, r, 0, 0, n - 1);
	}
	bool query(int a, int b, int l, int r, int node, int nl, int nr) {
		if (b < nl || nr < a) return true;
		if (a <= nl && nr <= b) return isgood(tree[node], l, r);
		int mid = (nl + nr) / 2;
		return query(a, b, l, r, 2 * node + 1, nl, mid) && query(a, b, l, r, 2 * node + 2, mid + 1, nr);
	}
};

bool cmp1(pair<int, int> aa, pair<int, int> bb) {
	if (aa.first != bb.first) return aa.first < bb.first;
	return aa.second > bb.second;
}

void show(vector<pair<int, int>> &a) {
	for (auto &i : a) printf("(%d, %d) ", i.first, i.second);
	cout << endl;
}

void fix1(vector<pair<int, int>> &a) {
	sort(a.begin(), a.end(), cmp1);
	static vector<pair<int, int>> b;
	b.clear();
	for (const auto &i : a) {
		while (b.size() && b.back().second >= i.second) b.pop_back();
		b.push_back(i);
	}
	a = b;
}

int n, q, k;
vector<vector<pair<int, int>>> a;

int main() {
	fast;
	cin >> n >> q >> k;

	a.resize(n);
	for (int i = 0, x, y, z; i < k; i++) {
		cin >> x >> y >> z;
		a[z - 1].emplace_back(x, y);
	}
	for (int i = 0; i < n; i++)
		fix1(a[i]);
	segtree T(a);

	while (q--) {
		int p[4];
		cin >> p[0] >> p[1] >> p[2] >> p[3];
		p[0]--, p[1]--;
		if (T.query(p[0], p[1], p[2], p[3])) cout << "yes" << endl;
		else cout << "no" << endl;
		fflush(stdout);
	}
}