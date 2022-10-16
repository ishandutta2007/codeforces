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

	void reset(set<int> &s) {
            for (int i: s) {
                  P[i] = i;
                  S[i] = 1;
            }
            s.clear();
	}
};

int M = 1e9+7;

int modpow(int n, int k) {
      if (k == -1) return 0;
      if (k == 0) return 1;
      if (k == 1) return n % M;

      int tmp = modpow(n, k/2);
      tmp = (tmp*tmp) % M;

      if (k & 1) tmp = (tmp*n) % M;
      return tmp;
}

DSU d(500001);
int n, m, k;
vector<int> a(500001);
vector<vector<int>> edge(1, vector<int>{-1, 0, 0});

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> m >> k;
      for (int i = 1; i <= n; i++) cin >> a[i];
      for (int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            edge.push_back({a[u]^a[v], u, v});
      }
      sort(edge.begin(), edge.end());

      int val = 1LL << k;
      int ans = 0;
      int cc = -1;
      set<int> s;
      for (int i = 1; i <= m; i++) {
            if (edge[i][0] != edge[i-1][0]) {
                  val--;
                  ans = (ans + modpow(2LL, cc)) % M;
                  cc = n;
                  d.reset(s);
            }

            int u = edge[i][1], v = edge[i][2];
            if (!d.same(u, v)) {
                  cc--;
                  d.merge(u, v);
                  s.insert(u); s.insert(v);
            }
      }
      ans = (ans + modpow(2LL, cc)) % M;

      val %= M;
      ans = (ans + val*modpow(2LL, n)) % M;

      cout << ans;

	return 0;
}