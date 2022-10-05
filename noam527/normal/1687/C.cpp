#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, m;
vector<ll> a, b;
vector<pair<int, int>> r;
vector<int> took;
vector<vector<int>> g;

void solve() {
	cin >> n >> m;
	a.resize(n);
	b.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	n++;

	r.resize(m);
	took.resize(m);
	g.clear();
	g.resize(n);
	for (int i = 0; i < m; i++) {
		took[i] = 0;
		cin >> r[i].first >> r[i].second;
		--r[i].first;
		g[r[i].first].push_back(i);
		g[r[i].second].push_back(i);
	}

	a.insert(a.begin(), 0LL);
	b.insert(b.begin(), 0LL);
	for (int i = 1; i < n; i++) {
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	if (a.back() != b.back()) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < n; i++)
		a[i] -= b[i];


	set<int> left;
	for (int i = 0; i < n; i++)
		if (a[i] != 0) left.insert(left.end(), i);


	queue<int> q;
	for (int i = 0; i < m; i++) {
		if (a[r[i].first] == 0 && a[r[i].second] == 0) {
			took[i] = 1;
			q.push(i);
		}
	}
	while (q.size() && left.size()) {
		int i = q.front();
		q.pop();
		int s = r[i].first, t = r[i].second;
		auto it = left.upper_bound(s);
		while (it != left.end() && *it < t) {
			int j = *it;
			left.erase(it);
			a[j] = 0;
			for (const auto &ed : g[j]) {
				if (!took[ed] && a[r[ed].first] == 0 && a[r[ed].second] == 0) {
					took[ed] = 1;
					q.push(ed);
				}
			}
			it = left.upper_bound(s);
		}
	}
	if (left.size() == 0) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}