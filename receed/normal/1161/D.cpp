#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

vector<vector<pair<int, int>>> g;
vector<int> col;
int m, MOD = 998244353;

void add_edge(int u, int v, int c) {
	g[u].push_back({v, c});
	g[v].push_back({u, c});
}

int dfs(int v, int cc) {
	col[v] = cc;
	for (auto &u : g[v]) {
		int nc = ((cc - 1) ^ u.second) + 1;
		if (col[u.first]) {
			if (col[u.first] != nc)
				return 1;
		}
		else if (dfs(u.first, nc))
			return 1;
	}
	return 0;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(n);
	rep(i, n) {
		a[i] = (s[i] == '?' ? 2 : s[i] - '0');
	}
	ll res = 0;
	for (int i = 1; i < n; i++) {
		m = n * 2 - i + 1;
		g.assign(m, vector<pair<int, int>>());
		rep(j, n / 2)
			add_edge(j, n - 1 - j, 0);
		rep(j, (n - i) / 2)
			add_edge(n + j, n + n - i - 1 - j, 0);
		rep(j, i)
			if (a[j] != 2)
				add_edge(m - 1, j, a[j]);
		rep(j, n - i)
			if (a[i + j] != 2)
				add_edge(i + j, n + j, a[i + j]);
		add_edge(n, m - 1, 1);
		ll ans = 1, pw = 0;
		col.assign(m, 0);
		rep(i, m)
			if (!col[i]) {
				if (dfs(i, 1)) {
					ans = 0;
					break;
				}
				pw++;
			}
		pw--;
		rep(i, pw)
			ans = ans * 2 % MOD;
		res = (res + ans) % MOD;
	}
	cout << res;
}