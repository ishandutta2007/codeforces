#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

  int N, M, K;
  N = 5; M = 5; K = 5;
  cin >> N >> M >> K;
  vector<vector<int>> A(N);
  for (int i = 0; i < N; i++) {
    int x = rnd() % 5 + 1;
    cin >> x;
    A[i].resize(x);
    for (int j = 0; j < x; j++) {
      A[i][j] = rnd() % K + 1;
      // cout << A[i][j] << " \n"[j + 1 == x];
      cin >> A[i][j];
      A[i][j]--;
    }
  }

  vector<int> brute(M);
  const auto Brute = [&](const auto &self, int pos) {
    if (pos == M) {
      const auto Count = [&](vector<int> b) {
        int res = 0;
        for (int i = 0; i + int(b.size()) - 1 < M; i++) {
          int ok = 1;
          for (int j = 0; j < int(b.size()); j++) {
            if (brute[i + j] != b[j]) {
              ok = 0;
              break;
            }
          }
          res += ok;
        }
        return res;
      };
      for (auto a : A) {
        int cnt = Count(a);
        for (int i = 0; i < int(a.size()); i++) {
          vector<int> b;
          for (int j = i; j < int(a.size()); j++) {
            b.emplace_back(a[j]);
            if (cnt < Count(b)) {
              return 0ll;
            }
          }
        }
      }
      return 1ll;
    }
    long long res = 0;
    for (int i = 0; i < K; i++) {
      brute[pos] = i;
      res += self(self, pos + 1);
    }
    return res;
  };
  // cout << Brute(Brute, 0) << '\n';

  map<int, int> occ;
  vector<int> invalid_chars(K);
  for (int i = 0; i < N; i++) {
    occ.clear();
    for (auto j : A[i]) {
      occ[j]++;
    }
    for (auto j : occ) {
      if (j.second > 1) {
        invalid_chars[j.first] = 1;
      }
    }
  }

  vector<set<int>> classes(K);
  for (int i = 0; i < N; i++) {
    for (auto j : A[i]) {
      classes[j].emplace(i);
    }
  }

  vector<int> par(K);
  iota(begin(par), end(par), 0);
  function<int(int)> Find = [&](int x) {
    return par[x] == x ? x : par[x] = Find(par[x]);
  };
  const auto Merge = [&](int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    par[x] = y;
    if (classes[x].size() > classes[y].size()) {
      swap(classes[x], classes[y]);
    }
    for (auto i : classes[x]) {
      classes[y].emplace(i);
    }
    classes[x].clear();
    return;
  };

  for (int i = 0; i < N; i++) {
    for (auto j : A[i]) {
      Merge(j, A[i][0]);
    }
  }

  const int MAX = 3e5 + 5;
  vector<int> item(MAX);
  for (int ch = 0; ch < K; ch++) {
    if (Find(ch) != ch) {
      continue;
    }
    if (classes[ch].empty()) {
      item[1] += 1;
      continue;
    }
    set<int> nodes;
    set<pair<int, int>> edges;
    auto &members = classes[ch];
    for (auto i : members) {
      for (int j = 0; j < int(A[i].size()); j++) {
        nodes.emplace(A[i][j]);
      }
      for (int j = 1; j < int(A[i].size()); j++) {
        edges.emplace(A[i][j - 1], A[i][j]);
      }
    }
    if (edges.size() + 1 != nodes.size()) {
      continue;
    }
    int bad = 0;
    for (auto u : nodes) {
      if (invalid_chars[u]) {
        bad = 1;
      }
    }
    if (bad) {
      continue;
    }
    map<int, int> indeg;
    map<int, int> outdeg;
    for (auto [u, v] : edges) {
      outdeg[u]++;
      indeg[v]++;
    }
    array<array<int, 2>, 2> cnt = {};
    for (auto u : nodes) {
      if (indeg[u] > 1 || outdeg[u] > 1) {
        continue;
      }
      cnt[indeg[u]][outdeg[u]] += 1;
    }
    if (nodes.size() == 1 || (cnt[0][1] == 1 && cnt[1][0] == 1 && cnt[1][1] == int(nodes.size()) - 2)) {
      item[nodes.size()] += 1;
    }
  }

  vector<pair<int, int>> items;
  for (int i = 0; i < MAX; i++) {
    if (item[i] > 0) {
      items.emplace_back(i, item[i]);
    }
  }

  using lint = long long;
  const lint MOD = 998244353;
  vector<lint> dp(M + 1);

  dp[0] = 1;
  for (int i = 0; i < M; i++) {
    for (auto [val, way] : items) {
      if (i + val <= M) {
        dp[i + val] += 1ll * dp[i] * way % MOD;
        dp[i + val] %= MOD;
      }
    }
  }
  cout << dp[M] << '\n';
  return 0;
}