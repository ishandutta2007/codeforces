#include <bits/stdc++.h>
#include <unordered_map>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct info {
	int from, to, ra;
	info() {
		to = from = ra = -1;
	}
	info(int f, int t, int r) {
		from = f;
		to = t;
		ra = r;
	}
} org[300003];

ll operator * (pair<int, int> &aa, pair<int, int> &bb) {
	return (ll)aa.first * bb.second + (ll)aa.second * bb.first;
}

int p[600000], r[600000] = {};
pair<int, int> cnt[600000];

struct dsu {
	int n;
	int nxt = 0;
	dsu() {}
	dsu(int sz) {
		n = sz;
		nxt = 0;
		for (int i = 0; i < n; i++) {
			p[i] = i;
			cnt[i] = (i < n / 2 ? make_pair(1, 0) : make_pair(0, 1));
		}
	}
	int find(int x) {
		while (x != p[x]) x = p[x];
		return x;
	}
	ll unite(int x, int y) {
		x--, y--;
		x = find(x), y = find(y);
		if (x == y) {
			org[nxt++] = info();
			return 0;
		}
		ll rtn = cnt[x] * cnt[y];
		if (r[y] > r[x]) {
			p[x] = y;
			org[nxt++] = (info(x, y, r[y]));
			cnt[y].first += cnt[x].first;
			cnt[y].second += cnt[x].second;
		}
		else {
			p[y] = x;
			org[nxt++] = (info(y, x, r[x]));
			if (r[x] == r[y]) r[x]++;
			cnt[x].first += cnt[y].first;
			cnt[x].second += cnt[y].second;
		}
		return rtn;
	}
	ll undo() {
		if (nxt == 0) return 0;
		info i = org[--nxt];
		if (i.from == -1) return 0;
		p[i.from] = i.from;
		r[i.to] = i.ra;
		cnt[i.to].first -= cnt[i.from].first;
		cnt[i.to].second -= cnt[i.from].second;
		return cnt[i.from] * cnt[i.to];
	}
};

ll H(pair<int, int> aa) {
	return 300003LL * aa.first + aa.second;
}
pair<int, int> H(ll aa) {
	return{ aa / 300003, aa % 300003 };
}

const int nn = 1 << 19;

int n, pr = 0;
ll ans = 0;
dsu D(600000);
map<ll, int> M;

vector<pair<int, int>> tree[2 * nn];

void add(int st, int en, const pair<int, int> &val, int node, int nl, int nr) {
	if (en < nl || nr < st) return;
	if (st <= nl && nr <= en) {
		if (OO) {
			cout << "added in " << node << " " << nl << " " << nr << '\n';
		}
		tree[node].push_back(val);
		return;
	}
	int mid = (nl + nr) / 2;
	add(st, en, val, 2 * node + 1, nl, mid);
	add(st, en, val, 2 * node + 2, mid + 1, nr);
}

void solve(int node, int nl, int nr) {
	if (nl >= n) return;
	for (auto &i : tree[node]) {
		ans += D.unite(i.first, 300000 + i.second);
	}
	if (2 * node + 2 < 2 * nn) {
		int mid = (nl + nr) / 2;
		solve(2 * node + 1, nl, mid);
		solve(2 * node + 2, mid + 1, nr);
	}
	else {
		cout << ans << " ";
		pr++;
		if (pr == n) {
			cout << '\n';
			exit(0);
		}
	}
	for (int i = 0; i < tree[node].size(); i++)
		ans -= D.undo();
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pair<int, int> pa = { x, y };
		ll h = H(pa);
		auto it = M.find(h);
		if (it != M.end()) {
			if (OO) {
				cout << "adding " << it->second << " " << i - 1 << " the pair " << x << " " << y << '\n';
			}
			add(it->second, i - 1, pa, 0, 0, nn - 1);
			M.erase(it);
		}
		else {
			M[h] = i;
		}
	}
	for (auto &i : M) {
		pair<int, int> pa = H(i.first);
		add(i.second, n - 1, pa, 0, 0, nn - 1);
	}
	solve(0, 0, nn - 1);
}