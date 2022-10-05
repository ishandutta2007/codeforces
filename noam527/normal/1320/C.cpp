#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
using namespace std;

struct segtree {
	int n;
	vector<ll> t, tag;
	segtree() {}
	segtree(const vector<ll> &cost) {
		n = max(2, (int)cost.size());
		while (n != (n & -n)) n += (n & -n);
		t.resize(2 * n, -inf);
		tag.resize(2 * n, 0);
		for (int i = 0; i < cost.size(); i++)
			t[i + n - 1] = cost[i];
		for (int i = n - 2; i >= 0; i--)
			fix(i);
	}
	void push(int x) {
		t[x] += tag[x];
		if (x < n - 1) {
			tag[x + x + 1] += tag[x];
			tag[x + x + 2] += tag[x];
		}
		tag[x] = 0;
	}
	void fix(int x) {
		push(x + x + 1), push(x + x + 2);
		t[x] = max(t[x + x + 1], t[x + x + 2]);
	}
	void upd(int l, int r, ll v) {
		upd(l, r, v, 0, 0, n - 1);
	}
	void upd(int l, int r, ll v, int node, int nl, int nr) {
		//cout << "upd " << l << " " << r << " " << v << " " << node << " " << nl << " " << nr << '\n';
		if (r < nl || nr < l) return;
		if (l <= nl && nr <= r) {
			tag[node] += v;
			return;
		}
		push(node);
		int mid = (nl + nr) / 2;
		upd(l, r, v, 2 * node + 1, nl, mid);
		upd(l, r, v, 2 * node + 2, mid + 1, nr);
		fix(node);
	}
	ll query() {
		return t[0];
	}
};

int n, m, p;
vector<pair<int, int>> a, b;
vector<vector<int>> mon;

map<int, int> compx, compy;

segtree T;

ll brute() {
	ll ans = -inf;
	for (int i = 0; i < a.size(); i++) for (int j = 0; j < b.size(); j++) {
		ll sum = -a[i].second - b[j].second;
		for (const auto &k : mon)
			if (k[0] <= a[i].first && k[1] <= b[j].first)
				sum += k[2];
		ans = max(ans, sum);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m >> p;
	a.resize(n);
	b.resize(m);
	mon.resize(p, vector<int>(3));
	for (auto &i : a) {
		cin >> i.first >> i.second;
		i.first--;
		compx[i.first] = 0;
	}
	for (auto &i : b) {
		cin >> i.first >> i.second;
		i.first--;
		compy[i.first] = 0;
	}
	for (auto &i : mon) {
		for (auto &j : i) cin >> j;
		compx[i[0]] = 0;
		compy[i[1]] = 0;
	}
	int nxt = 0;
	for (auto &i : compx) i.second = nxt++;
	nxt = 0;
	for (auto &i : compy) i.second = nxt++;
	for (auto &i : a) i.first = compx[i.first];
	for (auto &i : b) i.first = compy[i.first];
	for (auto &i : mon) {
		i[0] = compx[i[0]];
		i[1] = compy[i[1]];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(mon.begin(), mon.end());

	int X = compx.size(), Y = compy.size();

	vector<ll> cost(Y, -inf);
	for (auto &i : b) {
		cost[i.first] = max(cost[i.first], (ll)-i.second);
	}

	if (OO) {
		for (const auto &i : cost)
			cout << i << " "; cout << endl;
	}
	T = segtree(cost);
	nxt = 0;

	ll ans = -inf;

	for (const auto &i : a) {
		if (OO) {
			cout << "on query " << i.first << " " << i.second << '\n';
		}
		while (nxt < mon.size() && mon[nxt][0] <= i.first) {
			if (OO) {
				cout << "adding " << mon[nxt][1] << " " << Y - 1 << " " << mon[nxt][2] << endl;
			}
			T.upd(mon[nxt][1], Y - 1, mon[nxt][2]);
			nxt++;
		}
		ans = max(ans, T.query() - i.second);
	}
	cout << ans << '\n';
	//cout << brute() << '\n';
}