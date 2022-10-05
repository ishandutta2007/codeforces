#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

struct eve {
	ll t;
	int i;
	int op;
	eve() {}
	eve(ll tt, int ii, int oo) {
		t = tt;
		i = ii;
		op = oo;
	}
	bool operator < (const eve &a) const {
		if (t != a.t) return t < a.t;
		if (op != a.op) return op > a.op;
		return i < a.i;
	}
};

int n;
ll p;
vector<ll> t;
vector<ll> ans;
set<eve> E;

set<int> in, need;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> p;
	t.resize(n);
	ans.resize(n);
	for (auto &i : t) cin >> i;
	for (int i = 0; i < n; i++) E.insert(eve(t[i], i, 1));
	ll leave = 0;
	while (E.size()) {
		auto e = *E.begin();
		E.erase(E.begin());

		if (OO) {
			cout << "event: " << e.t << " " << e.i << " " << e.op << '\n';
			cout << "in: ";
			for (const auto &i : in) cout << i << " "; cout << '\n';
			cout << "need: ";
			for (const auto &i : need) cout << i << " "; cout << '\n';
		}

		if (e.op == 1) {
			need.insert(e.i);

			if (need.size() && *need.begin() < (in.size() ? *in.begin() : md)) {
				int v = *need.begin();
				need.erase(need.begin());
				leave = max(leave, e.t) + p;
				E.insert(eve(leave, v, -1));
				in.insert(v);
			}
		}
		else {
			in.erase(e.i);
			ans[e.i] = e.t;
			if (need.size() && *need.begin() < (in.size() ? *in.begin() : md)) {
				int v = *need.begin();
				need.erase(need.begin());
				leave = max(leave, e.t + p);
				E.insert(eve(e.t + p, v, -1));
				in.insert(v);
			}
		}
	}
	for (const auto &i : ans) cout << i << " "; cout << '\n';
}