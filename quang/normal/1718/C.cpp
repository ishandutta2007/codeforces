#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }

  auto GetDivs = [&](int x) {
    vector<int> res;
    for (int i = 2; i <= x; i++) {
      if (x % i == 0) {
        res.push_back(i);
        while (x % i == 0) {
          x /= i;
        }
      }
    }
    return res;
  };

  vector<int> divs = GetDivs(n);
  vector<vector<long long>> sum(divs.size());
  multiset<long long> ls;
  for (int i = 0; i < divs.size(); i++) {
    int mod = n / divs[i];

    sum[i] = vector<long long>(mod, 0ll);
    for (int j = 0; j < n; j++) {
      sum[i][j % mod] += a[j];
    }
    for (int j = 0; j < mod; j++) {
      ls.insert(sum[i][j] * mod);
    }
    debug(i, sum[i]);
  }

  auto Remove = [&](int u) {
    for (int i = 0; i < divs.size(); i++) {
      int mod = n / divs[i];
      ls.erase(ls.find(sum[i][u % mod] * mod));
      sum[i][u % mod] -= a[u];
      ls.insert(sum[i][u % mod] * mod);
    }
  };

  auto Add = [&](int u) {
    for (int i = 0; i < divs.size(); i++) {
      int mod = n / divs[i];
      ls.erase(ls.find(sum[i][u % mod] * mod));
      sum[i][u % mod] += a[u];
      ls.insert(sum[i][u % mod] * mod);
    }
  };

  cout << *ls.rbegin() << '\n';
  while (q--) {
    int p, x;
    cin >> p >> x;
    p--;
    Remove(p);
    a[p] = x;
    Add(p);
    cout << *ls.rbegin() << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}