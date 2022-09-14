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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 1 << 18;
vector<int> ls[N * 2], tr[N * 2];
int sz[N * 2], num[N * 2], cv, b[N], nb[N], a[N];

void pr(int v, int x) {
	for (int i = N + v; i; i /= 2)
		ls[i].push_back(x);
}

int lb(vector<int> &vv, int x) {
	return lower_bound(vv.begin(), vv.end(), x) - vv.begin();
}

void add(int p, int x, int v) {
	p = lb(ls[v], p);
	for (int i = sz[v] + p; i; i /= 2)
		tr[v][i] += x;
}

void add2(int p1, int p2, int x) {
	for (int i = N + p1; i; i /= 2)
		add(p2, x, i);
}

int sum(int cl, int cr, int v, int vn, int l, int r) {
	if (cr <= l || r <= cl)
		return 0;
	if (cl <= l && r <= cr)
		return tr[vn][v];
	return sum(cl, cr, v * 2, vn, l, (l + r) / 2) + sum(cl, cr, v * 2 + 1, vn, (l + r) / 2, r);
}

int sum2(int l1, int r1, int l2, int r2, int v=1, int l=0, int r=N) {
	if (r1 <= l || r <= l1)
		return 0;
	if (l1 <= l && r <= r1)
		return sum(lb(ls[v], l2), lb(ls[v], r2), 1, v, 0, sz[v]);
	return sum2(l1, r1, l2, r2, v * 2, l, (l + r) / 2) + 
		   sum2(l1, r1, l2, r2, v * 2 + 1, (l + r) / 2, r);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, t, l1, r1, l2, r2;
	cin >> n >> m;
	rep(i, n) {
		cin >> t;
		a[t - 1] = i;
	}
	rep(i, n) {
		cin >> nb[i];
		b[i] = a[nb[i] - 1];
		pr(i, b[i]);
	}
	vector<vector<int>> q(m, vector<int>(5));
	rep(i, m) {
		cin >> q[i][0] >> q[i][1] >> q[i][2];
		if (q[i][0] == 1)
			cin >> q[i][3] >> q[i][4];
		else {
			q[i][1]--; q[i][2]--;
			swap(b[q[i][1]], b[q[i][2]]);
			pr(q[i][1], b[q[i][1]]);
			pr(q[i][2], b[q[i][2]]);
		}
	}
	for (int i = 1; i < 2 * N; i++) {
		sort(ls[i].begin(), ls[i].end());
		ls[i].resize(unique(ls[i].begin(), ls[i].end()) - ls[i].begin());
		sz[i] = 1;
		while (sz[i] < ls[i].size())
			sz[i] *= 2;
		tr[i].assign(sz[i] * 2, 0);
	}
	rep(i, n) {
		b[i] = a[nb[i] - 1];
		add2(i, b[i], 1);
	}
	rep(i, m) {
		l1 = q[i][1]; r1 = q[i][2];
		l2 = q[i][3]; r2 = q[i][4];
		if (q[i][0] == 1) {
			cout << sum2(l2 - 1, r2, l1 - 1, r1) << '\n';
		}
		else {
			add2(l1, b[l1], -1);
			add2(r1, b[r1], -1);
			swap(b[l1], b[r1]);
			add2(l1, b[l1], 1);
			add2(r1, b[r1], 1);
		}
	}

}