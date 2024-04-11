#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}

	int find(int x) {
		while (x != P[x]) x = P[x];
		return x;
	}

	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (S[a] < S[b]) swap(a, b);

		S[a] += S[b];
		P[b] = a;
	}

	int same(int a, int b) {
		return find(a) == find(b);
	}
};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n, m; cin >> n >> m;
      vector<pair<int, int>> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i+1;
      }
      sort(a.begin(), a.end());

      vector<tuple<int, int, int>> edge;
      for (int i = 1; i < n; i++) {
            edge.emplace_back(a[0].first + a[i].first, a[0].second, a[i].second);
      }
      for (int i = 0; i < m; i++) {
            int x, y, z; cin >> x >> y >> z;
            edge.emplace_back(z, x, y);
      }
      sort(edge.begin(), edge.end());

      int ans = 0; DSU d(n);
      for (auto [w, x, y]: edge) {
            if (!d.same(x, y)) {
                  d.merge(x, y);
                  ans += w;
            }
      }
      cout << ans;

	return 0;
}