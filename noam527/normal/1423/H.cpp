#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct eve {
	int t, orig;
	int *x;
	eve() {
		x = 0;
	}
	eve(int ti, int val, int *at) {
		t = ti;
		orig = val;
		x = at;
	}
};

struct dsu {
	int n;
	vector<int> p, r, s;
	int nxttime = 0;
	vector<eve> e;
	dsu() {}
	dsu(int sz) {
		n = sz;
		p.resize(n, 0);
		r.resize(n, 0);
		s.resize(n, 1);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	int find(int x) {
		while (x != p[x]) x = p[x];
		return x;
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		nxttime++;
		if (x == y) {
			e.push_back(eve(nxttime, -1, 0));
			return;
		}
		if (r[x] < r[y]) {
			e.push_back(eve(nxttime, p[x], &p[x]));
			e.push_back(eve(nxttime, s[y], &s[y]));
			p[x] = y;
			s[y] += s[x];
		}
		else {
			e.push_back(eve(nxttime, p[y], &p[y]));
			e.push_back(eve(nxttime, s[x], &s[x]));
			p[y] = x;
			s[x] += s[y];
			if (r[x] == r[y]) {
				e.push_back(eve(nxttime, r[x], &r[x]));
				r[x]++;
			}
		}
	}
	int query(int x) {
		return s[find(x)];
	}
	void undo() {
		if (!e.size()) {
			cout << "weird\n";
			exit(0);
		}
		int t = e.back().t;
		while (e.size() && e.back().t == t) {
			eve tmp = e.back();
			e.pop_back();
			if (tmp.orig == -1) continue;
			*tmp.x = tmp.orig;
		}
	}
};

struct query {
	int t, x, y;
	query() {}
	query(int tt, int xx = -1, int yy = -1) {
		t = tt;
		x = xx;
		y = yy;
	}
};

const int N = 1 << 19;

int n, k, q;
vector<query> Q;
vector<int> starts;
int ask[2 * N];
vector<pair<int, int>> add[2 * N];

dsu D;

void upd(int l, int r, int x, int y, int node, int nl, int nr) {
	if (r < nl || nr < l) return;
	if (l <= nl && nr <= r) {
		add[node].emplace_back(x, y);
		return;
	}
	int mid = (nl + nr) / 2;
	upd(l, r, x, y, 2 * node + 1, nl, mid);
	upd(l, r, x, y, 2 * node + 2, mid + 1, nr);
}

void solve(int node, int nl, int nr) {
	for (const auto &e : add[node]) {
		D.unite(e.first, e.second);
	}
	if (nl == nr) {
		if (ask[nl] != -1) {
			cout << D.query(ask[nl]) << '\n';
		}
	}
	else {
		int mid = (nl + nr) / 2;
		solve(2 * node + 1, nl, mid);
		solve(2 * node + 2, mid + 1, nr);
	}
	for (const auto &e : add[node])
		D.undo();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q >> k;
	starts.push_back(0);
	for (int i = 0; i < 2 * N; i++) ask[i] = -1;
	for (int i = 0; i < q; i++) {
		int type, x, y;
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			--x, --y;
			Q.push_back(query(type, x, y));
		}
		else if (type == 2) {
			cin >> x;
			--x;
			Q.push_back(query(type, x));
			ask[i] = x;
		}
		else {
			Q.push_back(query(type));
			starts.push_back(i + 1);
		}
	}
	int group = 0;
	for (int i = 0; i < q; i++) {
		if (Q[i].t == 1) {
			int l = i;
			int r = N - 1;
			if (group + k < starts.size())
				r = starts[group + k] - 1;
			upd(l, r, Q[i].x, Q[i].y, 0, 0, N - 1);
		}
		else if (Q[i].t == 3) {
			group++;
		}
	}
	D = dsu(n);
	solve(0, 0, N - 1);
}