#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

ll gcd(ll x, ll y) {
	return !y ? x : gcd(y, x % y);
}

vector<pair<ll, int>> fix(vector<pair<ll, int>> &A, ll x) {
	vector<pair<ll, int>> rtn;
	for (const auto &i : A) {
		ll g = gcd(i.first, x);
		if (rtn.size() && rtn.back().first == g) rtn.back().second += i.second;
		else rtn.emplace_back(g, i.second);
	}
	if (rtn.size() && rtn.back().first == x) rtn.back().second++;
	else rtn.emplace_back(x, 1);
	return rtn;
}

int n;
vector<ll> w;
vector<vector<int>> g;
ll ans = 0;

void dfs(int v, int pre, vector<pair<ll, int>> A) {
	A = fix(A, w[v]);
	for (const auto &i : A)
		ans = (ans + i.first * i.second) % md;
	for (const auto &i : g[v])
		if (i != pre)
			dfs(i, v, A);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	w.resize(n);
	g.resize(n);
	for (auto &i : w) cin >> i;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<pair<ll, int>> A;
	dfs(0, 0, A);
	cout << ans << '\n';
}