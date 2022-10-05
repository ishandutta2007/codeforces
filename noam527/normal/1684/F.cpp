#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const int OO = 0;
using namespace std;

const int N = 200005;

struct lims {
	int l1, r1, l2, r2;
	lims() {}
	lims(int L1, int R1, int L2, int R2) {
		l1 = L1;
		r1 = R1;
		l2 = L2;
		r2 = R2;
	}
	bool operator < (const lims &a) const {
		return l1 < a.l1;
	}
};

int n, m;
vector<int> a;
vector<pair<int, int>> b;
vector<vector<int>> pos;
vector<int> prefmx;

int lim;
lims D[N];
vector<int> prefr2, sufr1;

void compress() {
	map<int, int> mm;
	for (auto &i : a) mm[i] = 0;
	int nxt = 0;
	for (auto &i : mm) i.second = nxt++;
	for (auto &i : a) i = mm[i];
}

void addlim(int l1, int r1, int l2, int r2) {
	D[lim] = lims(l1, r1, l2, r2);
	lim++;
}

void preprocess() {
	compress();
	pos.resize(n);
	for (auto &i : pos) i.clear();
	for (int i = 0; i < n; i++)
		pos[a[i]].push_back(i);

	sort(b.begin(), b.end());
	prefmx.resize(m);
	for (int i = 0; i < m; i++)
		prefmx[i] = b[i].second;
	for (int i = 1; i < m; i++)
		prefmx[i] = max(prefmx[i - 1], prefmx[i]);
}

int maximumr(int upto) {
	if (b[m - 1].first <= upto) return prefmx[m - 1];
	if (b[0].first > upto) return -1;

	int lo = 0, hi = m - 1, mid;
	while (lo < hi) {
		mid = (lo + hi + 1) / 2;
		if (b[mid].first <= upto) lo = mid;
		else hi = mid - 1;
	}
	return prefmx[lo];
}

int build_lims() {
	lim = 0;
	for (int v = 0; v < n; v++) {
		if (pos[v].size() == 0) break;
		if (pos[v].size() == 1) continue;
		for (int i = 0; i + 1 < pos[v].size(); i++) {
			int r = maximumr(pos[v][i]);
			if (r < pos[v][i]) continue;
			if (OO) cout << pos[v][i] << " " << r << '\n';
			int j = upper_bound(pos[v].begin(), pos[v].end(), r) - pos[v].begin();
			j--;
			if (i == j) continue;
			addlim(pos[v][i], pos[v][j - 1], pos[v][i + 1], pos[v][j]);
		}
	}
	if (lim == 0) return -1;
	if (OO) {
		cout << "lim: " << lim << '\n';
	}
	sort(D, D + lim);
	if (OO) {
		for (int i = 0; i < lim; i++) {
			cout << D[i].l1 << " " << D[i].r1 << " " << D[i].l2 << " " << D[i].r2 << '\n';
		}
	}
	prefr2.resize(lim);
	sufr1.resize(lim);
	prefr2[0] = D[0].r2;
	for (int i = 1; i < lim; i++)
		prefr2[i] = max(prefr2[i - 1], D[i].r2);
	sufr1[lim - 1] = D[lim - 1].r1;
	for (int i = lim - 2; i >= 0; i--)
		sufr1[i] = max(sufr1[i + 1], D[i].r1);

	int res = D[0].l2;
	for (int i = 1; i < lim; i++)
		res = min(res, D[i].l2);
	return res;
}

int query(int L) {
	if (D[lim - 1].l1 < L) return prefr2[lim - 1];
	int lo = 0, hi = lim - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		if (D[mid].l1 < L) lo = mid + 1;
		else hi = mid;
	}

	if (lo == 0) return sufr1[0];
	if (lo == lim) return prefr2[lim - 1];
	return max(sufr1[lo], prefr2[lo - 1]);
}

void solve() {
	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i.first >> i.second, --i.first, --i.second;
	preprocess();
	int upto = build_lims();
	if (lim == 0) {
		cout << "0\n";
		return;
	}
	int ans = md;
	for (int L = 0; L <= upto; L++) {
		int R = query(L);
		if (OO) {
			cout << "L R " << L << " " << R << '\n';
		}
		ans = min(ans, R - L + 1);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}