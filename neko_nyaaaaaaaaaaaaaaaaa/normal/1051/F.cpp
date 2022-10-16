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

int n, m;
int INF = 1000000000000000000LL;
vector<int> parent(100005);
vector<int> level(100005);
vector<vector<int>> sp(100005, vector<int>(22, -1));
vector<vector<pair<int, int>>> adj(100005);
vector<int> w(100005);
vector<vector<int>> edge;

vector<vector<int>> dijk;
set<int> e;

void LCAinit() {
      for(int i = 1; i <= n; i++){
            sp[i][0] = parent[i];
      }

      for (int j = 1; (1 << j) < n; j++) {
            for (int i = 1; i <= n; i++) {
                 if(sp[i][j-1] != -1){
                        sp[i][j] = sp[sp[i][j-1]][j-1] ;
                  }
            }
      }
}

int LCA(int u, int v) {
      if (level[u] < level[v]) {
            swap(u, v);
      }

      int dist = level[u] - level[v] ;
      while(dist > 0){
            int raise_by = log2(dist);
            u = sp[u][raise_by];
            dist -= (1 << raise_by) ;
      }
      if(u == v) return u;

      for (int j = 20; j >= 0; j--) {
            if (sp[u][j] != -1 && sp[u][j] != sp[v][j]) {
                  u = sp[u][j];
                  v = sp[v][j];
            }
      }

      return parent[u];
}

void dfs(int now, int prev, int weight) {
      level[now] = level[prev] + 1;
      parent[now] = prev;
      w[now] = weight;
      for (auto u: adj[now]) {
            if (u.first != prev) {
                  dfs(u.first, now, weight + u.second);
            }
      }
}

vector<int> dijkstra(int start) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      vector<int> dist(100005, INF);
      vector<int> vis(100005);
      dist[start] = 0;

      pq.push({0, start});
      while (pq.size()) {
            auto tmp = pq.top();
            int now = tmp.second, w = tmp.first;
            pq.pop();

            if (vis[now]) continue;
            vis[now] = 1;

            for (auto u: adj[now]) {
                  if (dist[now] + u.second < dist[u.first]) {
                        dist[u.first] = dist[now] + u.second;
                        pq.push({dist[u.first], u.first});
                  }
            }
      }

      return dist;
}

void input() {
      cin >> n >> m;

      DSU d(n);
      for (int i = 1; i <= m; i++) {
            int x, y, z; cin >> x >> y >> z;
            if (!d.same(x, y)) {
                  adj[x].push_back({y, z});
                  adj[y].push_back({x, z});
                  d.merge(x, y);
            } else {
                  edge.push_back({x, y, z});
            }
      }

      dfs(1, 0, 0);
      LCAinit();
}

void solve() {
      for (auto ee: edge) {
            int u = ee[0], v = ee[1], w = ee[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            e.insert(u); e.insert(v);
      }

      for (int st: e) {
            dijk.push_back(dijkstra(st));
      }
}

void answer() {
      int q; cin >> q;
      while (q--) {
            int u, v; cin >> u >> v;
            int ans = w[u] + w[v] - 2*w[LCA(u, v)];

            for (int i = 0; i < dijk.size(); i++) {
                  ans = min(ans, dijk[i][u] + dijk[i][v]);
            }
            cout << ans << '\n';
      }
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      input();
      solve();
      answer();

      return 0;
}