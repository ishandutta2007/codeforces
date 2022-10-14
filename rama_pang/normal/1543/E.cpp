#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const int DEBUG = 0;

void Main() {
  int N;
  cin >> N;
  vector<vector<int>> adj(1 << N);
  if (!DEBUG) {
    for (int i = 0; i < N * (1 << (N - 1)); i++) {
      int u, v;
      cin >> u >> v;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }
  } else {
    for (int i = 0; i < (1 << N); i++) {
      for (int x = 0; x < N; x++) {
        adj[i].emplace_back(i ^ (1 << x));
      }
    }
  }

  for (int i = 0; i < (1 << N); i++) {
    sort(begin(adj[i]), end(adj[i]));
    assert(adj[i].size() == N);
  }

  vector<int> hyperName(1 << N, -1);
  hyperName[0] = 0;
  for (int i = 0; i < N; i++) {
    hyperName[1 << i] = adj[0][i];
  }
  for (int c = 2; c <= N; c++) {
    for (int name = 0; name < (1 << N); name++) {
      if (__builtin_popcount(name) != c) {
        continue;
      }

      int x = -1, y = -1;
      for (int i = 0; i < N; i++) {
        if ((name >> i) & 1) {
          if (x == -1) {
            x = i;
          } else if (y == -1) {
            y = i;
            break;
          }
        }
      }

      assert(x != -1 && y != -1);
      int u, v, w;
      u = name ^ (1 << x);
      v = name ^ (1 << y);
      w = name ^ (1 << x) ^ (1 << y);

      const auto Intersect = [&](int a, int b) {
        vector<int> res;
        for (auto c : adj[a]) {
          if (binary_search(begin(adj[b]), end(adj[b]), c)) {
            res.emplace_back(c);
          }
        }
        return res;
      };

      assert(hyperName[u] != -1);
      assert(hyperName[v] != -1);
      assert(hyperName[w] != -1);

      vector<int> isect = Intersect(hyperName[u], hyperName[v]);
      assert(isect.size() == 2);
      assert(isect[0] == hyperName[w] || isect[1] == hyperName[w]);
      hyperName[name] = isect[0] ^ isect[1] ^ hyperName[w];
    }
  }

  for (int i = 0; i < (1 << N); i++) {
    cout << hyperName[i] << ' ';
  }
  cout << '\n';

  if ((1 << N) % N != 0) {
    cout << -1 << '\n';
    return;
  }

  vector<int> color(1 << N);
  for (int i = 0; i < (1 << N); i++) {
    for (int j = 0; j < N; j++) {
      if ((i >> j) & 1) {
        color[i] ^= j;
      }
    }
  }

  vector<int> realColor(1 << N);
  for (int i = 0; i < (1 << N); i++) {
    realColor[hyperName[i]] = color[i];
  }
  for (int i = 0; i < (1 << N); i++) {
    cout << realColor[i] << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}