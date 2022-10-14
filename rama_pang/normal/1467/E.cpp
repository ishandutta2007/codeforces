#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  vector<vector<int>> adj(N);
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }  

  // If 3 in single path, ans = 0
  bool noans = false;
  map<int, int> all;
  for (int i = 0; i < N; i++) {
    all[A[i]]++;
  }
  vector<int> where(N, -1);
  vector<map<int, int>> cnt(N);
  function<void(int, int)> Dfs = [&](int u, int p) {
    int deg = 0;
    cnt[u][A[u]]++;
    for (auto v : adj[u]) if (v != p) {
      Dfs(v, u);
      auto it = cnt[v].find(A[u]);
      if (cnt[v][A[u]] > 0) {
        deg++;
        where[u] = v;
      }
      if (cnt[u].size() < cnt[v].size()) {
        swap(cnt[u], cnt[v]);
      }
      for (auto x : cnt[v]) {
        cnt[u][x.first] += x.second;
      }
      cnt[v].clear();
    }
    if (all[A[u]] - cnt[u][A[u]] > 0) deg++;
    if (deg > 1) noans = true;
  };
  Dfs(0, -1);
  if (noans) {
    cerr << "noans\n";
    cout << 0 << '\n';
    return 0;
  }

  // Interval Range Update
  vector<int> seg(2 * N);
  const auto Update = [&](int l, int r, int x) {
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
      if (l & 1) seg[l++] += x;
      if (r & 1) seg[--r] += x;
    }
  };
  const auto Query = [&](int p) {
    int res = 0;
    for (p += N; p > 0; p /= 2) {
      res += seg[p];
    }
    return res;
  };

  int T = 0;
  vector<int> st(N), et(N), depth(N);
  vector<vector<int>> lift(N, vector<int>(20, -1));
  function<void(int, int)> Dfs2 = [&](int u, int p) {
    lift[u][0] = p;
    st[u] = T++;
    for (auto v : adj[u]) if (v != p) {
      depth[v] = depth[u] + 1;
      Dfs2(v, u);
    }
    et[u] = T;
  };
  Dfs2(0, -1);
  for (int j = 1; j < 20; j++) {
    for (int i = 0; i < N; i++) {
      if (lift[i][j - 1] == -1) {
        lift[i][j] = -1;
      } else {
        lift[i][j] = lift[lift[i][j - 1]][j - 1];
      }
    }
  }

  const auto Lca = [&](int x, int y) {
    if (depth[x] > depth[y]) {
      swap(x, y);
    }
    int cc = depth[y] - depth[x];
    for (int i = 0; i < 20; i++) {
      if ((cc >> i) & 1) {
        y = lift[y][i];
      }
    }
    for (int i = 19; i >= 0; i--) {
      if (lift[x][i] != lift[y][i]) {
        x = lift[x][i];
        y = lift[y][i];
      }
    }
    return x == y ? x : lift[x][0];
  };

  map<int, vector<int>> ls;
  for (int i = 0; i < N; i++) {
    ls[A[i]].emplace_back(i);
  }

  for (auto elem : ls) {
    auto v = elem.second;
    sort(begin(v), end(v));
    if (v.size() == 1) {
      continue;
    }
    int w = v[0];
    for (auto i : v) {
      w = Lca(w, i);
    }
    for (auto i : v) {
      if (i == w) {
        Update(0, N, 1);
        if (where[i] != -1) {
          Update(st[where[i]], et[where[i]], -1);
        }
      } else {
        Update(st[i], et[i], 1);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    cerr << Query(st[i]) << ' ';
    if (Query(st[i]) == 0) {
      ans += 1;
    }
  }

  cout << ans << '\n';
  return 0;
}

/*
5
1 3 3 1 3
1 2
2 3
3 4 
4 5

5
1 1 2 3 4
1 2
1 3
2 4
2 5
*/