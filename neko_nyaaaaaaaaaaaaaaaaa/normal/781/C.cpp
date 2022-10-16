#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

int n, m, k;
vector<int> adj[200005];
vector<int> e;

void dfs(int now, int prev) {
      e.push_back(now);
      for (int u: adj[now]) {
            if (u != prev) {
                  dfs(u, now);
                  e.push_back(now);
            }
      }
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> m >> k;
      DSU d(n);
      while (m--) {
            int x, y; cin >> x >> y;
            if (x != y && !d.same(x, y)) {
                  d.merge(x, y);
                  adj[x].push_back(y);
                  adj[y].push_back(x);
            }
      }
      dfs(1, 0);

      int lim = (2*n + k - 1)/k;
      int petr = 0;
      vector<int> c;
      int cl = 0;
      while (petr < e.size()) {
            c.push_back(e[petr]);
            petr++;

            if (c.size() == lim) {
                  cl++;
                  cout << lim << " ";
                  for (int i: c) cout << i << " ";
                  cout << '\n';
                  c.clear();
            }
      }
      if (c.size()) {
            cl++;
            cout << c.size() << " ";
            for (int i: c) cout << i << " ";
            cout << '\n';
            c.clear();
      }
      while (cl < k) {
            cl++;
            cout << "1 1\n";
      }

      return 0;
}