#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}
	
	int find(int x) {
		if (x == P[x]) return x;
		return P[x] = find(P[x]);
	}
	
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return 0;
		if (S[a] < S[b]) swap(a, b);
		
		S[a] += S[b];
		P[b] = a;
		return 1;
	}
	
	int same(int a, int b) {
		return find(a) == find(b);
	}
};


#define int long long

int m, n;
vector<int> a(100005);
vector<int> b(100005);

bool cmp(int x, int y) {
	if (b[x] != b[y]) return b[x] > b[y];
	return x < y;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int j = 1; j <= n; j++) {
		cin >> b[j];
	}
	int ans = 0, sum = 0;

	vector<tuple<int, int, int>> edges;
	for (int i = 1; i <= m; i++) {
		int k; cin >> k;
		vector<int> g;
		while (k--) {
			int x; cin >> x;
			g.push_back(x);
			sum += a[i] + b[x];
		}
		sort(g.begin(), g.end(), cmp);
		ans += a[i] + b[g[0]];

		for (int j = 1; j < g.size(); j++) {
			edges.emplace_back(a[i] + b[g[j]], g[0], g[j]);
		}
	}

	sort(edges.begin(), edges.end());
	reverse(edges.begin(), edges.end());
	DSU d(n);
	for (auto [cost, u, v]: edges) {
		if (d.merge(u, v)) {
			ans += cost;
		}
	}

	cout << sum-ans << '\n';

	return 0;
}