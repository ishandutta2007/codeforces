#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 3e5 + 5;

int n, q, p[N], sz[N], centroid[N], mx[N];
vector<int> g[N];

bool isCentroid(int x, int up_size) {
	int mxx = max(sz[mx[x]], up_size);
	return 2 * mxx <= sz[x] + up_size;
}

void dfs(int x) {
	sz[x] = 1;
	mx[x] = 0;
	for (int i : g[x]) {
		if (i == p[x]) continue;
		dfs(i);
		sz[x] += sz[i];
		if (sz[i] > sz[mx[x]]) {
			mx[x] = i;
		}
	}
	if (2 * sz[mx[x]] > sz[x]) {
		int i = centroid[mx[x]];
		while (!isCentroid(i, sz[x] - sz[i])) {
			i = p[i];
		}
		centroid[x] = i;
	} else {
		centroid[x] = x;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		g[i].push_back(p[i]);
		g[p[i]].push_back(i);
	}

	dfs(1);

	while (q--) {
		int v;
		cin >> v;
		cout << centroid[v] << '\n';
	}
	return 0;
}