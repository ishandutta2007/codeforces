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
vector <int> c, ans, children;
vector <bool> used;
bool is = true;
void check(int v) {
	used[v] = true;
	for (auto u : a[v]) {
		if (used[u]) continue;
		check(u);
		children[v] += children[u] + 1;
	}
	if (c[v] > children[v]) is = false;
}
void dfs(int v) {
	used[v] = true;
	int cnt = -1;
	for (int i = 1; i <= ans.size() - 1; ++i) {
		cnt += (ans[i] == 0);
		if (cnt == c[v]) {
			ans[i] = v;
			break;
		}
	}
	for (auto u : a[v]) {
		if (used[u]) continue;
		dfs(u);
	}
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n; cin >> n;
	int st = 0;
	a.resize(n + 1);
	c.resize(n + 1);
	used.resize(n + 1);
	ans.resize(n + 1);
	children.resize(n + 1);
	for (int i = 1, p, x; i <= n; ++i) {
		cin >> p >> x;
		c[i] = x;
		if (!p) st = i;
		else {
			a[i].push_back(p);
			a[p].push_back(i);
		}
	}
	check(st);
	for (int i = 1; i <= n; ++i) used[i] = false;
	dfs(st);
	if (!is) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
		vector <int> hah(n + 1);
		for (int i = 1; i <= n; ++i)
			hah[ans[i]] = i;
		for (int i = 1; i <= n; ++i) 
			cout << hah[i] << ' ';
		cout << '\n';
	}
	return 0;
}