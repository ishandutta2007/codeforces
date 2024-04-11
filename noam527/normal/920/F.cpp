#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

struct fenwick {
	int n;
	vector<ll> tree;

	fenwick(const vector<int> &a) {
		n = a.size() - 1;
		tree.resize(n + 1);
		for (int i = 1, j; i <= n; i++) {
			tree[i] += a[i];
			j = i + (i & -i);
			if (j <= n) tree[j] += tree[i];
		}
	}
	// set position x to v.
	void upd(int x, int v) {
		static int ch;
		ch = v - query(x, x);
		for (; x <= n; x += (x & -x)) tree[x] += ch;
	}
	ll quer(int x) {
		static ll rtn;
		rtn = 0;
		for (; x; x -= (x & -x)) rtn += tree[x];
		return rtn;
	}
	ll query(int st, int en) {
		return quer(en) - quer(st - 1);
	}
};

const int lim = 1e6 + 6;

int n, q, p[3];
vector<int> a, D(lim);

void work() {
	vector<vector<pair<int, int>>> D2(lim);
	vector<bool> b(lim, true);
	for (int i = 2; i < lim; i++) {
		if (b[i]) {
			for (int j = i; j < lim; j += i) {
				b[j] = false;
				if (D2[j / i].size() && D2[j / i].back().first == i)
					D2[j].push_back({ i, D2[j / i].back().second + 1 });
				else
					D2[j].push_back({ i, 1 });
			}
		}
	}
	for (int i = 2; i < lim; i++) {
		D[i] = 1;
		for (const auto &j : D2[i])
			D[i] *= (j.second + 1);
	}
}

int main() {
	fast;
	work();

	cin >> n >> q;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	stack<int> toerase;
	fenwick f(a);
	set<int> active;
	for (int i = 1; i <= n; i++) if (a[i] > 2) active.insert(i);

	while (q--) {
		cin >> p[0] >> p[1] >> p[2];
		if (p[0] == 1) {
			for (auto it = active.lower_bound(p[1]); it != active.end() && *it <= p[2]; it++) {
				a[*it] = D[a[*it]];
				f.upd(*it, a[*it]);
				if (a[*it] < 3) toerase.push(*it);
			}
			while (!toerase.empty()) {
				active.erase(toerase.top());
				toerase.pop();
			}
		}
		else
			cout << f.query(p[1], p[2]) << endl;
	}
}