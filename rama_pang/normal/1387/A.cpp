#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, M;
  cin >> N >> M;

  vector<vector<pair<int, int>>> adj(N);
  for (int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;
    adj[u].emplace_back(v, 2 * c);
    adj[v].emplace_back(u, 2 * c);
  }

  const int UNDET = 1e9;
  vector<int> ans(N, UNDET);
  vector<set<pair<int, int>>> state(N);
  vector<int> trial(N, UNDET);

  for (int i = 0; i < N; i++) {
    if (ans[i] != UNDET) {
      continue;
    }
    static queue<int> q;
    static vector<int> vis;
    q.emplace(i);
    state[i].insert({1, 0}); // ax + b, x = ans[i]
    while (!q.empty()) {
      int u = q.front();
      vis.emplace_back(u);
      q.pop();
      for (auto e : adj[u]) {
        int v = e.first;
        int c = e.second;
        for (auto it : state[u]) {
          if (state[v].count({-it.first, c - it.second}) == 0) {
            state[v].insert({-it.first, c - it.second});
            q.emplace(v);
          }
        }
        if (state[v].size() > 2) {
          cout << "NO\n";
          return 0;
        }
      }
    }

    int x = UNDET;
    for (auto u : vis) {
      if (state[u].size() == 1) {
        continue;
      }
      int a = begin(state[u])->first;
      int b = begin(state[u])->second;
      int c = next(begin(state[u]))->first;
      int d = next(begin(state[u]))->second;
      if (a == c && b != d) {
        cout << "NO\n";
        return 0;
      }
      x = (d - b) / (a - c);
      break;
    }
    
    if (x != UNDET) {
      for (auto u : vis) {
        ans[u] = begin(state[u])->first * x + begin(state[u])->second;
      }
      for (auto u : vis) {
        for (auto e : adj[u]) {
          int v = e.first;
          int c = e.second;
          if (ans[u] + ans[v] != c) {
            cout << "NO\n";
            return 0;
          }
        }
      }
    } else {
      auto FindCost = [&](int st) {
        for (auto u : vis) {
          trial[u] = UNDET;
        }
        trial[i] = st;
        long long cur = 0;
        bool can = true;
        for (auto u : vis) {
          if (!can) {
            break;
          }
          cur += max(trial[u], -trial[u]);
          for (auto e : adj[u]) {
            int v = e.first;
            int c = e.second;
            if (trial[v] == UNDET) {
              trial[v] = c - trial[u];
            }
            if (trial[u] + trial[v] != c) {
              can = false;
              break;
            }
          }
        }
        return can ? cur : UNDET;
      };

      int lo = -1e7, hi = 1e7;
      while (lo < hi) {
        int md = (lo + hi) >> 1;
        if (FindCost(md) < FindCost(md + 1)) {
          hi = md;
        } else {
          lo = md + 1;
        }
      }
      FindCost(lo);
      for (auto u : vis) {
        ans[u] = trial[u];
      }
    }
    vis.clear();
    if (ans[i] == UNDET) {
      cout << "NO\n";
      return 0;
    }
  }

  cout << "YES\n";
  for (int i = 0; i < N; i++) {
    cout << (double) ans[i] / 2 << " ";
  }
  cout << "\n";
  return 0;
}