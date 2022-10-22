#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
vector <vector <int>> a;
vector <bool> used;
vector <int> children, maxcomp;
void dfs(int v) {
	used[v] = true;
	int n = a.size() - 1;
	for (auto u : a[v]) {
		if (used[u]) continue;
		dfs(u);
		children[v] += children[u] + 1;
		maxcomp[v] = max(maxcomp[v], children[u] + 1);
	}
	maxcomp[v] = max(maxcomp[v], n - children[v] - 1);
}
pair <int, int> finding(int v, int x1, int x2) {
	used[v] = true;
	for (auto u : a[v]) {
		if (u == x2 and v == x1) continue;
		if (used[u]) continue;
		if (children[u] == 0) return { v, u };
		pair <int, int> cur = finding(u, x1, x2);
		if (cur.first) return cur;
		
	}
	return { 0, 0 };
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int testcases;
	cin >> testcases;
	while (testcases --> 0) {
		int n; cin >> n;
		a.resize(0);
		a.resize(n + 1);
		used.resize(0);
		used.resize(n + 1);
		children.resize(0);
		children.resize(n + 1);
		maxcomp.resize(0);
		maxcomp.resize(n + 1);
		for (int i = 0, u, v; i < n - 1; ++i) {
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs(1);
		int mn = 1e9, cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (maxcomp[i] < mn)
				mn = maxcomp[i], cnt = 1;
			else if (maxcomp[i] == mn)
				++cnt;
		}
		if (cnt == 1) {
			cout << "1 " << a[1][0];
			cout << "\n1 " << a[1][0] << '\n';
			continue;
		}
		int x1 = 0, x2 = 0;
		for (int i = 1; i <= n; ++i) {
			if (maxcomp[i] == mn)
				if (x1) x2 = i;
				else x1 = i;
		}
		for (int i = 1; i <= n; ++i)
			used[i] = false, children[i] = 0;
		dfs(x1);
		for (int i = 1; i <= n; ++i)
			used[i] = false;
		pair <int, int> res = finding(x1, x1, x2);
		cout << res.first << ' ' << res.second << '\n';
		cout << x2 << ' ' << res.second << '\n';
	}
	return 0;
}