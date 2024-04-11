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

int n;
ll a[2001][2001];
vector<pair<int, ll>> adj[2001];

void dfs(int now, int prev, int source, ll dist) {
      if (a[source][now] != dist) {cout << "NO"; exit(0);}
      for (auto u: adj[now]) {
            if (u.first != prev) {
                  dfs(u.first, now, source, dist + u.second);
            }
      }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      vector<tuple<int, int, int>> edge;
      for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                  cin >> a[i][j];
                  if (i == j) {
                        if (a[i][j]) {cout << "NO"; return 0;}
                  } else {
                        if (!a[i][j]) {cout << "NO"; return 0;}
                        if (i < j) edge.emplace_back(a[i][j], i, j);
                  }
            }
      }

      DSU dd(n);
      sort(edge.begin(), edge.end());
      for (auto [d, u, v]: edge) {
            if (!dd.same(u, v)) {
                  dd.merge(u, v);
                  adj[u].push_back({v, d});
                  adj[v].push_back({u, d});
            }
      }

      for (int i = 1; i <= n; i++) {
            dfs(i, 0, i, 0);
      }
      cout << "YES";

	return 0;
}