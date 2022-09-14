#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>

typedef long long ll;
typedef long double ld;
using namespace std;

int q(char c, int v) {
	cout << c << ' ' << v << endl;
	int u;
	cin >> u;
	return u;
}

int dfs(int v, int p, vector<vector<int>> &g, vector<int> &used) {
	if (used[v])
		return v;
	for (int u : g[v])
		if (u != p) {
			int t = dfs(u, v, g, used);
			if (t)
				return t;
		}
	return 0;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, n, u, v, k1, k2;
	cin >> t;
	for (int z = 0; z < t; z++) {
		cin >> n;
		vector<vector<int>> g(n + 1);
		vector<int> used(n + 1), u2(n + 1);
		for (int i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cin >> k1;
		vector<int> v1(k1);
		for (int i = 0; i < k1; i++) {
			cin >> v1[i];
			used[v1[i]] = 1;
		}
		cin >> k2;
		vector<int> v2(k2);
		for (int i = 0; i < k2; i++) {
			cin >> v2[i];
			u2[v2[i]] = 1;
		}
		int cv = q('B', v2[0]);
		if (used[cv]) {
			cout << "C " << cv << endl;
			continue;
		}
		int tv = dfs(cv, -1, g, used), nv = q('A', tv);
		if (!u2[nv])
			tv = -1;
		cout << "C " << tv << endl;
	}
}