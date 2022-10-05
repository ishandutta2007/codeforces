#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
using namespace std;

void debug(string names) {
	cout << '\n';
}
template<typename A1, typename... A2>
void debug(string names, A1 par, A2... left) {
	int pos = 0;
	for (; pos < names.size() && names[pos] != ' ' && names[pos] != ','; pos++)
		cout << names[pos];
	cout << ": " << par << "  ";
	while (pos < names.size() && (names[pos] == ' ' || names[pos] == ',')) {
		pos++;
	}
	names.erase(names.begin(), names.begin() + pos);
	debug(names, left...);
}

int n;
vector<vector<int>> g;
vector<ll> s, a;

void dfs(int v = 0, int prev = -1, ll sum = 0) {
	if (g[v].size() == 1 && prev != -1) {
		if (s[v] == -1) a[v] = 0;
		else {
			if (sum > s[v]) {
				cout << -1 << '\n';
				exit(0);
			}
			a[v] = s[v] - sum;
		}
		return;
	}
	if (s[v] == -1) {
		ll mn = 1e18;
		for (const auto &i : g[v])
			if (i != prev)
				mn = min(mn, s[i]);
		if (sum > mn) {
			cout << -1 << '\n';
			exit(0);
		}
		a[v] = mn - sum;
		for (const auto &i : g[v])
			if (i != prev) 
				dfs(i, v, mn);
	}
	else {
		if (sum > s[v]) {
			cout << -1 << '\n';
			exit(0);
		}
		a[v] = s[v] - sum;
		for (const auto &i : g[v])
			if (i != prev)
				dfs(i, v, s[v]);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	g.resize(n);
	s.resize(n);
	a.resize(n);
	for (int i = 1, x; i < n; i++) {
		cin >> x;
		--x;
		g[i].push_back(x);
		g[x].push_back(i);
	}
	for (auto &i : s) cin >> i;
	dfs();
	ll ans = 0;
	for (const auto &i : a) ans += i;
	finish(ans);
}