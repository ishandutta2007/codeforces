#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int off = 1e5 + 5;

struct fenwick {
	int n = off + off + 5;
	int t[off + off + 5];
	fenwick() {
		clear();
	}
	void clear() {
		n = off + off + 5;
		for (int i = 0; i < n; i++) t[i] = 0;
	}
	void upd(int x) {
		for (; x <= n; x += (x & -x)) t[x]++;
	}
	int query(int x) {
		int rtn = 0;
		for (; x; x -= (x & -x)) rtn += t[x];
		return rtn;
	}
	int bquery(int x) {
		return query(off + off + 3) - query(x - 1);
	}
};

struct info {
	int val, f, i;
	info() {}
	info(int vv, int ff, int ii) {
		val = vv;
		f = ff;
		i = ii;
	}
	bool operator < (const info &a) const {
		return f > a.f;
	}
};

int n, q;
vector<int> a;
vector<pair<char, int>> Q;
int dom[off + off + 1] = {};
int nxt = off + off;

void upd(int val) {
	int aa = val;
	if (val < off) val = 2 * off - val;
	while (nxt > val) {
		dom[nxt] = aa;
		dom[2 * off - nxt] = aa;
		nxt--;
	}
}

vector<int> up[off + off + 5], down[off + off + 5];
vector<info> cur;
vector<int> ans;

void query(int val) {
	int d = dom[val], ind = 0;
	if (d) {
		int U = (up[d].size() ? up[d].back() : -1);
		int D = (down[d].size() ? down[d].back() : -1);
		if (U > D) {
			ind = U + 1;
			val = min(val, 2 * off - val);
		}
		else {
			ind = D + 1;
			val = max(val, 2 * off - val);
		}
	}
	if (down[max(val, 2 * off - val)].size() && ind <= down[max(val, 2 * off - val)].back()) {
		val = max(val, 2 * off - val);
		ind = down[max(val, 2 * off - val)].back() + 1;
	}
	if (up[min(val, 2 * off - val)].size() && ind <= up[min(val, 2 * off - val)].back()) {
		val = min(val, 2 * off - val);
		ind = up[min(val, 2 * off - val)].back() + 1;
	}
	cur.push_back(info(val, ind, cur.size()));
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		i += off;
	}
	for (int i = 0; i < q; i++) {
		char op;
		int val;
		cin >> op >> val;
		val += off;
		if (op == '>') up[val].push_back(i);
		else down[val].push_back(i);

		Q.push_back({ op, val });
	}
	for (int i = q - 1; i >= 0; i--)
		upd(Q[i].second);

	ans.resize(n);
	for (auto &i : a) query(i);

	sort(cur.begin(), cur.end());
	fenwick F;
	int nxt = q - 1;
	for (auto &i : cur) {
		while (nxt >= i.f) {
			if (Q[nxt].first == '<' && Q[nxt].second > off)
				F.upd(Q[nxt].second);
			else if (Q[nxt].first == '>' && Q[nxt].second < off)
				F.upd(2 * off - Q[nxt].second);
			nxt--;
		}
		int c = F.bquery(max(i.val, 2 * off - i.val));
		if (c & 1) i.val = 2 * off - i.val;
		ans[i.i] = i.val;
	}
	for (const auto &i : ans) cout << i - off << " "; cout << '\n';
}