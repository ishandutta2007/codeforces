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

void dfs(int v, vector<vector<int>> &g, vector<int> &used) {
	used[v] = 1;
	for (int u : g[v])
		if (!used[u])
			dfs(u, g, used);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> a(n), b(n);
	vector<vector<int>> g(n);
	int l = -1;
	for(int j = 0; j < 2; j++) {
		l = -1;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i]) {
				if (l != -1) {
					if (j == 0)
						g[l].push_back(i);
					else
						g[i].push_back(l);
				}
				l = i;
			}
		}
	}
	vector<int> used(n, 0);
	dfs(0, g, used);
	if (used[s - 1])
		cout << "YES\n";
	else
		cout << "NO\n";
}