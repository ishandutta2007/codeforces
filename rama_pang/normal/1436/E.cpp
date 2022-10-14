#include <bits/stdc++.h>
using namespace std;

int Brute(int n, vector<int> a) {
  set<int> all;
  for (int i = 0; i < n; i++) {
    set<int> s;
    for (int j = i; j < n; j++) {
      s.emplace(a[j]);
      for (int k = 1; true; k++) {
        if (s.count(k) == 0) {
          all.emplace(k);
          break;
        }
      }
    }
  }
  for (int i = 1; true; i++) {
    if (all.count(i) == 0) {
      return i;
    }
  }
  return -1;
}

int Solve(int n, vector<int> a) {
  vector<vector<int>> occ(n + 1);
  for (int i = 0; i <= n; i++) {
    occ[i].emplace_back(-1);
  }
  for (int i = 0; i < n; i++) {
    a[i]--;
    occ[a[i]].emplace_back(i);
  }
  for (int i = 0; i <= n; i++) {
    occ[i].emplace_back(n);
  }

  vector<int> in(n + 2);
  vector<pair<int, int>> queries;
  for (int val = 0; val <= n; val++) {
    auto &pos = occ[val];
    for (int i = 0; i + 1 < (int) pos.size(); i++) {
      if (pos[i] + 1 <= pos[i + 1] - 1) {
        queries.emplace_back(pos[i] + 1, pos[i + 1] - 1);
      }
    }
  }

  sort(begin(queries), end(queries), [&](pair<int, int> x, pair<int, int> y) {
    return x.second < y.second;
  });


  int sz = 1;
  while (sz < 2 * n) {
    sz *= 2;
  }
  vector<int> tree(2 * sz, -1);

  const auto Update = [&](int pos, int val) {
    tree[pos += sz] = val;
    for (pos /= 2; pos > 0; pos /= 2) {
      tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
    }
  };

  const auto Query = [&](int lft) {
    int node = 1;
    while (node < sz) {
      if (tree[node * 2] < lft) {
        node = node * 2;
      } else {
        node = node * 2 + 1;
      }
    }
    return node - sz;
  };

  int ptr = 0;
  for (auto q : queries) {
    while (ptr <= q.second) {
      Update(a[ptr], ptr);
      ptr++;
    }
    in[Query(q.first)] = 1;
  }

  for (int i = 0; i <= n + 1; i++) {
    if (!in[i]) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int LOCAL = 0;
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

  int n;
  if (LOCAL) {
    n = 6;
  } else {
    cin >> n;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    if (LOCAL) {
      a[i] = rnd() % (n / 2) + 1;
    } else {
      cin >> a[i];
    }
  }

  if (LOCAL) {
    cout << n << "\n";
    for (auto i : a) {
      cout << i << " ";
    }
    cout << "\n";
  }
  // cout << Brute(n, a) << "\n";
  cout << Solve(n, a) << "\n";
  return 0;
}

/*

20
3 6 4 9 9 3 2 10 6 1 4 3 2 4 6 10 8 8 5 6
ans: 6

*/