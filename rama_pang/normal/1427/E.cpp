#include <bits/stdc++.h>
using namespace std;
using lint = long long;

class Gaussian {
 public:
  mt19937 rnd;
  vector<lint> basis;

  Gaussian() : rnd(chrono::high_resolution_clock::now().time_since_epoch().count()) {}

  bool Insert(lint x) {
    for (auto i : basis) {
      if ((x ^ i) < x) {
        x ^= i;
      }
    }
    if (x != 0) {
      basis.emplace_back(x);
      for (int i = (int) basis.size() - 1; i > 0; i--) {
        if (basis[i - 1] < basis[i]) {
          swap(basis[i - 1], basis[i]);
        }
      }
    }
    return x != 0;
  }

  lint GetRandom() {
    lint res = 0;
    for (auto i : basis) {
      if (rnd() & 1) {
        res ^= i;
      }
    }
    return res;
  }

  bool IsIndependent(lint x) {
    for (auto i : basis) {
      if ((i ^ x) < x) {
        x ^= i;
      }
    }
    return x != 0;
  }

  void Backtrack(lint x, vector<array<lint, 3>> &op, bool getrand) {
    lint res = 0;
    for (auto i : basis) {
      if ((x ^ i) < x) {
        if (getrand) {
          op.push_back({1, res, i});
          res ^= i;
        } else {
          op.push_back({1, i, x});
        }
        x ^= i;
      }
    }
  }
};

void Main() {
  lint X;
  cin >> X;
 
  vector<array<lint, 3>> ans;
  ans.push_back({1, X, X});

  Gaussian G;
  G.Insert(X);
  
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
  vector<lint> A = {X};
  
  while (G.IsIndependent(1)) {
    int u = rnd() % A.size();
    int v = rnd() % A.size();
    if (A[u] + A[v] < (lint) 4e18 && G.IsIndependent(A[u] + A[v])) {
      ans.push_back({0, A[u], A[v]});
      A.emplace_back(A[u] + A[v]);
      if (G.IsIndependent(A[u] + A[v])) {
        G.Backtrack(A[u] + A[v], ans, false);
        G.Insert(A[u] + A[v]);
      }
    }
  }
 
  assert(count(begin(G.basis), end(G.basis), 1) > 0);
  assert(ans.size() <= 100000);
 
  cout << ans.size() << "\n";
  for (auto i : ans) {
    if (i[0] == 0) {
      cout << i[1] << " + " << i[2] << "\n";
    } else {
      cout << i[1] << " ^ " << i[2] << "\n";
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}