#include <bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int OneEdge(int u, int v) {
  cout << 1 << ' ' << u << ' ' << v << endl;
  int foo;
  cin >> foo;
  return foo;
}

int ManyEdges(int u, vector<int> v) {
  cout << 2 << ' ' << u << ' ' << v.size();
  for (auto i : v) cout << ' ' << i;
  cout << endl;
  int foo;
  cin >> foo;
  return foo;
}

vector<vector<int>> getMap(int N) {
  vector<vector<int>> res(N, vector<int>(N));

  const auto MergeSort = [&](const auto &self, int l, int r) -> vector<int> {
    if (l == r) return {l};
    int md = (l + r) / 2;
    vector<int> v1 = self(self, l, md);
    vector<int> v2 = self(self, md + 1, r);

    vector<int> res;

    reverse(begin(v1), end(v1));
    reverse(begin(v2), end(v2));

    while (!v1.empty() && !v2.empty()) {
      if (OneEdge(v1.back(), v2.back())) {
        res.emplace_back(v1.back());
        v1.pop_back();
      } else {
        res.emplace_back(v2.back());
        v2.pop_back();
      }
    }

    while (!v1.empty()) {
      res.emplace_back(v1.back());
      v1.pop_back();
    }

    while (!v2.empty()) {
      res.emplace_back(v2.back());
      v2.pop_back();
    }

    return res;
  };

  vector<int> topo = MergeSort(MergeSort, 0, N - 1);

  vector<vector<int>> st;
  const auto CompareInStack = [&](int u) {
    vector<int> q;
    for (auto i : st) for (auto j : i) q.emplace_back(j);
    return ManyEdges(u, q);
  };

  for (auto u : topo) {
    vector<int> merged = {u};
    while (!st.empty() && CompareInStack(u)) {
      vector<int> top = st.back();
      st.pop_back();
      for (auto v : top) {
        merged.emplace_back(v);
      }
    }
    st.emplace_back(merged);
  }

  for (int i = 0; i < int(st.size()); i++) { // SCC = st
    for (int j = i; j < int(st.size()); j++) {
      for (auto u : st[i]) {
        for (auto v : st[j]) {
          res[u][v] = 1;
        }
      }
    }
  }

  for (int i = 0; i < N; i++) {
    res[i][i] = 1;
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        res[i][j] |= res[i][k] && res[k][j];
      }
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto res = getMap(n);
    cout << 3 << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << res[i][j];
      }
      cout << endl;
    }
    int foo;
    cin >> foo;
    if (foo == -1) {
      break;
    }
  }
  return 0;
}