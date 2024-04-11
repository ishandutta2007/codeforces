#include <bits/stdc++.h>
using namespace std;
using lint = long long;

vector<int> ls[1 << 21];

void Main() {
  int n;
  cin >> n;

  int ans_mx = 0;
  vector<int> ans(2 * n);
  iota(begin(ans), end(ans), 0);

  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  
  auto Solve = [&](int c, vector<int> colors) {
    vector<vector<array<int, 3>>> adj(c);
    vector<bool> done(2 * n, false);
    for (int i = 0; i < n; i++) {
      adj[colors[i * 2]].push_back({colors[i * 2 + 1], i * 2, i * 2 + 1});
      adj[colors[i * 2 + 1]].push_back({colors[i * 2], i * 2 + 1, i * 2});
    }
    for (int i = 0; i < c; i++) {
      if (adj[i].size() % 2 != 0) {
        return vector<int>();
      }
    }

    vector<int> res;
    function<void(int)> Dfs = [&](int u) {
      while (!adj[u].empty()) {
        array<int, 3> nxt = adj[u].back();
        adj[u].pop_back();
        if (done[nxt[1]] || done[nxt[2]]) {
          continue;
        }
        done[nxt[1]] = done[nxt[2]] = 1;
        Dfs(nxt[0]);
        res.emplace_back(nxt[2]);
        res.emplace_back(nxt[1]);
      }
    };

    Dfs(0);
    // for (auto i : res) cout << i+1 << " "; cout << "\n";
    if (res.size() == 2 * n && colors[res.front()] == colors[res.back()]) {
      return res;
    } else {
      return vector<int>();
    }
  };

  for (int mx = 0; mx < 20; mx++) {
    int mask = (1 << (mx + 1)) - 1;
    for (int i = 0; i <= mask; i++) {
      ls[i].clear();
    }
    for (int i = 0; i < 2 * n; i++) {
      ls[a[i] & mask].emplace_back(i);
    }
    vector<int> colors(2 * n, -1);
    int c = 0;
    for (int i = 0; i <= mask; i++) {
      if (!ls[i].empty()) {
        for (auto j : ls[i]) {
          if (colors[j] != -1) {
            assert(false);
          }
          colors[j] = c;
        }
        c++;
      }
    }
    for (int i = 0; i < 2 * n; i++) {
      if (colors[i] == -1) {
        assert(false);
      }
    }
    vector<int> s = Solve(c, colors);
    if (!s.empty()) {
      ans_mx = mx + 1;
      ans = s;
    }
    
    // cout << "mx: " << mx << "\n";
    // for (int i = 0; i < n; i++) {
    //   cout << colors[i * 2] << " " << colors[i * 2 + 1] << "\n";
    // }
  }

  cout << ans_mx << "\n";
  for (auto i : ans) cout << i + 1 << " ";
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
/*
5
5 1
5 0
5 10
6 6
10 2
*/