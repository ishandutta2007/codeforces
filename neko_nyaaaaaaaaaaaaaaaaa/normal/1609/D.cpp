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

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	DSU d(n); int spare_edges = 0;
	while (m--) {
		int x, y; cin >> x >> y;
		if (!d.merge(x, y)) {
			spare_edges++;
		}

		// don't use x and y anymore after this point

		vector<int> ccs; // just store their sizes is enough
		for (int i = 1; i <= n; i++) {
			if (d.find(i) == i) {
				// this is a root
				ccs.push_back(d.S[d.find(i)]); // d.S[i] would work too, since i is a root anyway
			}
		}

		sort(ccs.begin(), ccs.end(), greater<int>());
		int ans = 0;
		for (int i = 0; i <= spare_edges; i++) {
			ans += ccs[i];
		}
		cout << ans-1 << '\n';
	}

	return 0;
}