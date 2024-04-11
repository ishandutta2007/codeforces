#include <bits/stdc++.h>
using namespace std;

class Fenwick {
 public:
  int sz;
  vector<int> tree;

  Fenwick(int sz) : sz(sz), tree(sz) {} 

  void Update(int p, int x) {
    for (int i = p; i < sz; i |= i + 1) tree[i] += x;
  }

  int Query(int p) {
    int res = 0;
    for (int i = p + 1; i > 0; i &= i - 1) res += tree[i - 1];
    return res;
  }
};

void Main() {
  int n, t;
  cin >> n >> t;

  map<int, int> memo;
  Fenwick subtract(n + 5);
  const auto Query = [&](int r) { // number of 0s
    if (memo.count(r)) {
      return memo[r] - subtract.Query(r);
    }
    cout << "? " << 1 << ' ' << r << endl;
    int foo;
    cin >> foo;
    memo[r] = r - foo + subtract.Query(r);
    return r - foo;
  };

  const auto Update = [&](int x) {
    subtract.Update(x, 1);
  };

  while (t--) {
    int k;
    cin >> k;

    int lo = 1, hi = n;
    while (lo < hi) {
      int md = (lo + hi) / 2;
      if (Query(md) >= k) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }

    Update(lo);
    cout << "! " << lo << endl;
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