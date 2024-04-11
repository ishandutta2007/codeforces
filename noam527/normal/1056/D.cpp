#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
vector<vector<int>> g;
int cnt = 0;
vector<int> ans, ans2;
vector<int> sz, c;
int C;

void pre(int v = 0, int prev = -1) {
	if (g[v].size() == 1 && prev != -1) {
		sz[v] = c[v] = 1;
		return;
	}
	sz[v] = 1;
	c[v] = 0;
	for (const auto &i : g[v])
		if (i != prev) {
			pre(i, v);
			sz[v] += sz[i];
			c[v] += c[i];
		}
}

void calc(int v, int prev, int lim) {
	if (c[v] <= lim) {
		C += sz[v];
		return;
	}
	for (const auto &i : g[v])
		if (i != prev)
			calc(i, v, lim);
}

void solve(int l, int r, int stv, int env) {
	if (l > r) return;
	if (stv == env) {
		for (int i = l; i <= r; i++) ans[i] = stv;
		return;
	}
	int mid = (stv + env) / 2;
	C = 0;
	calc(0, -1, mid);
	cout << "mid C " << mid << " " << C << endl;
	solve(l, C, stv, mid);
	solve(C + 1, r, mid + 1, env);
}

int main() {
	fast;
	cin >> n;
	if (n == 1) finish(1);
	g.resize(n);
	ans.resize(n + 1);
	for (int i = 1, x; i < n; i++) {
		cin >> x;
		--x;
		g[i].push_back(x);
		g[x].push_back(i);
	}
	for (int i = 1; i < n; i++)
		if (g[i].size() == 1) cnt++;

	sz.resize(n);
	c.resize(n);
	pre();
	sort(c.begin(), c.end());
	int A = 0, nxt = 0;
	for (int i = 1; i <= n; i++) {
		while (nxt < n && c[nxt] <= i) {
			nxt++;
		}
		ans[i] = nxt;
	}
	ans2.resize(n + 1, inf);
	for (int i = 1; i <= n; i++)
		ans2[ans[i]] = min(ans2[ans[i]], i);
	for (int i = n - 1; i >= 1; i--)
		ans2[i] = min(ans2[i], ans2[i + 1]);
	for (int i = 1; i <= n; i++) cout << ans2[i] << " "; cout << endl;
}