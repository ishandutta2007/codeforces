#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1.01e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  vector<int> order(n);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return l[i] < l[j];
  });
  vector<int> roots;
  vector<int> st;
  vector<vector<int>> g(n);
  for (int i : order) {
    while (!st.empty() && l[i] > r[st.back()]) {
      st.pop_back();
    }
    if (st.empty()) {
      roots.push_back(i);
    } else {
      g[st.back()].push_back(i);
    }
    st.push_back(i);
  }
  vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(2, vector<vector<int>>(2)));
  vector<int> al(n), ar(n);
  function<void(int)> Dfs = [&](int i) {
    for (int j : g[i]) {
      Dfs(j);
    }
    for (int x = 0; x < 2; x++) {
      for (int y = 0; y < 2; y++) {
        if (g[i].empty()) {
          dp[i][x][y].resize(1);
          dp[i][x][y][0] = r[i] - l[i];
        } else {
          vector<vector<vector<int>>> aux(g[i].size() + 1, vector<vector<int>>(2));
          aux[0][0].assign(1, -inf);
          aux[0][0][0] = (x == 1 ? l[g[i][0]] - l[i] : 0);
          aux[0][1].assign(2, -inf);
          aux[0][1][1] = l[g[i][0]] - l[i];
          for (int p = 0; p < (int) g[i].size(); p++) {
            for (int px = 0; px < 2; px++) {
              for (int py = 0; py < 2; py++) {
                int dx = (p == 0 ? x : 0) | px;
                int dy = (p == (int) g[i].size() - 1 ? y : 0) | py;
                int me = (int) aux[p][px].size();
                int them = (int) dp[g[i][p]][dx][dy].size();
                int need = me + them - 1 + py;
                int add_v = 0;
                if (p == (int) g[i].size() - 1) {
                  add_v = (py == 1 || y == 1) * (r[i] - r[g[i][p]]);
                } else {
                  add_v = (py == 1) * (l[g[i][p + 1]] - r[g[i][p]]);
                }
                while ((int) aux[p + 1][py].size() < max((int) aux[p + 1][py].size(), need)) {
                  aux[p + 1][py].push_back(-inf);
                }
                for (int u = 0; u < (int) aux[p][px].size(); u++) {
                  for (int v = 0; v < (int) dp[g[i][p]][dx][dy].size(); v++) {
                    if (aux[p][px][u] >= 0 && dp[g[i][p]][dx][dy][v] >= 0) {
                      int ft = aux[p][px][u] + dp[g[i][p]][dx][dy][v] + add_v;
                      if (ft > aux[p + 1][py][u + v + py]) {
                        aux[p + 1][py][u + v + py] = ft;
                      }
                    }
                  }
                }
              }
            }
          }
          for (int py = 0; py < 2; py++) {
            for (int u = 1; u < (int) aux.back()[py].size(); u++) {
              if (aux.back()[py][u] < 0) {
                continue;
              }
              int put = u - 1;
              while ((int) dp[i][x][y].size() <= put) {
                dp[i][x][y].push_back(-inf);
              }
              dp[i][x][y][put] = max(dp[i][x][y][put], aux.back()[py][u]);
            }
          }
        }
      }
    }
  };
  function<void(int, int, int, int, int, vector<int>)> Restore = [&](int i, int x, int id_x, int y, int id_y, vector<int> inner) {
    assert(inner.size() < dp[i][x][y].size());
    if (g[i].empty()) {
      al[i] = l[i];
      ar[i] = r[i];
      return;
    }
    vector<vector<vector<int>>> aux(g[i].size() + 1, vector<vector<int>>(2));
    vector<vector<vector<int>>> pr(g[i].size() + 1, vector<vector<int>>(2));
    vector<vector<vector<int>>> pu(g[i].size() + 1, vector<vector<int>>(2));
    vector<vector<vector<int>>> pv(g[i].size() + 1, vector<vector<int>>(2));
    aux[0][0].assign(1, -inf);
    aux[0][0][0] = (x == 1 ? l[g[i][0]] - l[i] : 0);
    aux[0][1].assign(2, -inf);
    aux[0][1][1] = l[g[i][0]] - l[i];
    for (int p = 0; p < (int) g[i].size(); p++) {
      for (int px = 0; px < 2; px++) {
        for (int py = 0; py < 2; py++) {
          int dx = (p == 0 ? x : 0) | px;
          int dy = (p == (int) g[i].size() - 1 ? y : 0) | py;
          int me = (int) aux[p][px].size();
          int them = (int) dp[g[i][p]][dx][dy].size();
          int need = me + them - 1 + py;
          int add_v = 0;
          if (p == (int) g[i].size() - 1) {
            add_v = (py == 1 || y == 1) * (r[i] - r[g[i][p]]);
          } else {
            add_v = (py == 1) * (l[g[i][p + 1]] - r[g[i][p]]);
          }
          while ((int) aux[p + 1][py].size() < max((int) aux[p + 1][py].size(), need)) {
            aux[p + 1][py].push_back(-inf);
            pr[p + 1][py].push_back(-1);
            pu[p + 1][py].push_back(-1);
            pv[p + 1][py].push_back(-1);
          }
          for (int u = 0; u < (int) aux[p][px].size(); u++) {
            for (int v = 0; v < (int) dp[g[i][p]][dx][dy].size(); v++) {
              if (aux[p][px][u] >= 0 && dp[g[i][p]][dx][dy][v] >= 0) {
                int ft = aux[p][px][u] + dp[g[i][p]][dx][dy][v] + add_v;
                if (ft > aux[p + 1][py][u + v + py]) {
                  aux[p + 1][py][u + v + py] = ft;
                  pr[p + 1][py][u + v + py] = px;
                  pu[p + 1][py][u + v + py] = u;
                  pv[p + 1][py][u + v + py] = v;
                }
              }
            }
          }
        }
      }
    }
    vector<int> take(g[i].size() + 1, -1);
    int cc = -1;
    for (int py = 0; py < 2; py++) {
      for (int u = 1; u < (int) aux.back()[py].size(); u++) {
        if (aux.back()[py][u] < 0) {
          continue;
        }
        int put = u - 1;
        if (put == (int) inner.size() && aux.back()[py][u] == dp[i][x][y][put]) {
          take.back() = py;
          cc = u;
        }
      }
    }
    assert(take.back() != -1);
    vector<int> go_in(g[i].size());
    for (int p = (int) g[i].size() - 1; p >= 0; p--) {
      take[p] = pr[p + 1][take[p + 1]][cc];
      go_in[p] = pv[p + 1][take[p + 1]][cc];
      cc = pu[p + 1][take[p + 1]][cc];
    }
    inner.push_back(i);
    for (int p = 0; p <= (int) g[i].size(); p++) {
      if (take[p] == 0) {
        take[p] = -1;
      } else {
        assert(!inner.empty());
        take[p] = inner.back();
        inner.pop_back();
        al[take[p]] = (p == 0 ? l[i] : r[g[i][p - 1]]);
        ar[take[p]] = (p == (int) g[i].size() ? r[i] : l[g[i][p]]);
      }
    }
    if (take[0] == -1 && x == 1) {
      take[0] = id_x;
      ar[id_x] = l[g[i][0]];
    }
    if (take.back() == -1 && y == 1) {
      take.back() = id_y;
      al[id_y] = r[g[i].back()];
    }
    assert(accumulate(go_in.begin(), go_in.end(), 0) == (int) inner.size());
    for (int p = 0; p < (int) g[i].size(); p++) {
      int nx = 0;
      int nid_x = -1;
      int ny = 0;
      int nid_y = -1;
      if (take[p] != -1) {
        nx = 1;
        nid_x = take[p];
      }
      if (take[p + 1] != -1) {
        ny = 1;
        nid_y = take[p + 1];
      }
      vector<int> ninner;
      while (go_in[p] > 0) {
        assert(!inner.empty());
        ninner.push_back(inner.back());
        inner.pop_back();
        go_in[p] -= 1;
      }
      Restore(g[i][p], nx, nid_x, ny, nid_y, ninner);
    }
  };
  int ans = 0;
  for (int x : roots) {
    Dfs(x);
    assert(!dp[x][0][0].empty());
    ans += dp[x][0][0][0];
    Restore(x, 0, -1, 0, -1, vector<int>());
  }
  int total = 0;
  for (int i = 0; i < n; i++) {
    assert(l[i] <= al[i] && al[i] < ar[i] && ar[i] <= r[i]);
    total += ar[i] - al[i];
  }
  assert(total == ans);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return al[i] < al[j];
  });
  for (int i = 0; i < n - 1; i++) {
    assert(ar[order[i]] <= al[order[i + 1]]);
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << al[i] << " " << ar[i] << '\n';
  }
  return 0;
}