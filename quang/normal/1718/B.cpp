#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 42
#endif

void Solve(int test) {
  int n;
  cin >> n;
  if (n == 1) {
    int u;
    cin >> u;
    cout << (u == 1 ? "YES" : "NO") << '\n';
    return;
  }
  multiset<int> m;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int u;
    cin >> u;
    m.insert(u);
    sum += u;
  }
  long long sum_fib = 2;
  vector<long long> fib = {1, 1};
  while (sum_fib < sum) {
    fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    sum_fib += fib.back();
  }
  if (sum_fib != sum) {
    cout << "NO\n";
    return;
  }
  int next = 0;
  for (int i = fib.size() - 1; i >= 0; i--) {
    if (m.empty()) {
      cout << "NO\n";
      return;
    }
    auto u = *m.rbegin();
    m.erase(m.find(u));
    if (u < fib[i]) {
      cout << "NO\n";
      return;
    }
    u -= fib[i];
    if (next) {
      m.insert(next);
    }
    next = u;
  }
  assert(m.empty());
  cout << "YES\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}