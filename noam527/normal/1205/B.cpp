#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<ll> a;
vector<int> c;
vector<vector<int>> g;
vector<int> d;

int calc(int u, int v) {
	if (OO) cout << "u v " << u << " " << v << endl;
	for (auto &i : d) i = -1;
	d[u] = 0;
	queue<int> q;
	for (const auto &i : g[u])
		if (i != v) {
			q.push(i);
			d[i] = 1;
		}
	while (q.size()) {
		int x = q.front();
		q.pop();
		for (const auto &i : g[x]) {
			if (d[i] == -1) {
				d[i] = 1 + d[x];
				q.push(i);
			}
		}
	}
	if (OO) {
		for (const auto &i : d) cout << i << " "; cout << endl;
	}
	if (d[v] == -1) return md;
	return d[v] + 1;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	c.resize(70, 0);
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (auto &k : a) {
		for (ll i = 0, b = 1; b <= k; b *= 2, i++)
			if (k & b)
				c[i]++;
	}
	for (auto &i : c)
		if (i >= 3) finish(3);
	sort(a.rbegin(), a.rend());
	while (a.size() && a.back() == 0) a.pop_back();
	if (a.size() == 0) finish(-1);
	n = a.size();

	g.resize(n);
	d.resize(n);

	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		if (i != j && (a[i] & a[j]) != 0) {
			g[i].push_back(j);
		}
	int ans = md;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)
		if (i != j && (a[i] & a[j]) != 0) {
			ans = min(ans, calc(i, j));
		}
	if (ans == md) finish(-1);
	finish(ans);
}