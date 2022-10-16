#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
vector<int> adj[100005];
vector<int> ans(100005, 200005);
unordered_set<int> red;

vector<int> parent(100005);
vector<int> level(100005);
vector<vector<int>> sp(100005, vector<int>(22, -1));

void LCAInit() {
      for(int i = 1; i <= n; i++){
            sp[i][0] = parent[i] ;
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

int dist(int u, int v) {
      return level[u] + level[v] - 2*level[LCA(u, v)];
}

void dfs(int now, int prev) {
      parent[now] = prev;
      level[now] = level[prev] + 1;
      for (int u: adj[now]) {
            if (u != prev) dfs(u, now);
      }
}

void process() {
      queue<int> q;
      vector<int> vis(n+1);
      for (int u: red) {
            ans[u] = 0;
            q.push(u);
      }
      red.clear();

      while (q.size()) {
            int now = q.front();
            q.pop();

            if (vis[now]) continue;
            vis[now] = 1;

            for (int u: adj[now]) {
                  q.push(u);
                  ans[u] = min(ans[u], ans[now] + 1);
            }
      }
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> q;
      for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      dfs(1, 0);
      red.insert(1);
      LCAInit();

      int k = 500;
      while (q--) {
            k--;
            if (k == 0) {
                  k = 500;
                  process();
            }

            int t, v; cin >> t >> v;
            if (t == 1) {
                  red.insert(v);
            } else {
                  int res = ans[v];
                  for (int u: red) {
                        res = min(res, dist(v, u));
                  }
                  cout << res << '\n';
            }
      }

      return 0;
}