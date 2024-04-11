#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, p[200001], r[200001], sz[200001];
vector<vector<int>> g;
vector<int> cyc;
ll ans = 0;

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int size(int x) {
	return sz[find(x)];
}

bool iscyc(int x) {
	return cyc[find(x)];
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) {
		if (r[x] > r[y]) p[y] = x, sz[x] += sz[y], cyc[x] = cyc[x] || cyc[y];
		else {
			p[x] = y, sz[y] += sz[x], cyc[y] = cyc[y] || cyc[x];
			if (r[x] == r[y]) r[y]++;
		}
	}
}

bool cmp(vector<int> &a, vector<int> &b) {
	return a[2] > b[2];
}

int main() {
	fast;
	cin >> n >> m;
	g.resize(m, vector<int>(3));
	cyc.resize(n, 0);
	for (int i = 0; i < m; i++)
		cin >> g[i][0] >> g[i][1] >> g[i][2];
	for (int i = 0; i < n; i++)
		p[i] = i, r[i] = 0, sz[i] = 1;
	sort(g.begin(), g.end(), cmp);
	for (int i = 0; i < m; i++) {
		if (find(g[i][0]) != find(g[i][1]) && (!iscyc(g[i][0]) || !iscyc(g[i][1]))) {
			ans += g[i][2];
			unite(g[i][0], g[i][1]);
		}
		else if (!iscyc(g[i][0])) {
			cyc[find(g[i][0])] = 1;
			ans += g[i][2];
		}
	}

	cout << ans << endl;
}