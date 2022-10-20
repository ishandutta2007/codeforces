#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  bool f = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] % 2 != i % 2) {
      f = 1;
    }
  }
  if (f) {
    cout << -1 << '\n';
    return;
  }
  vector<int> res;
  for (int t = n; t > 1; t -= 2) {
    int post = 0;
    int post1 = 0;
    for (int i = 1; i <= t; i++) {
      if (a[i] == t) post = i;
      if (a[i] == t - 1) post1 = i;
    }

    auto Do = [&](int x) {
      res.push_back(x);
      if (post <= x) post = x - post + 1;
      if (post1 <= x) post1 = x - post1 + 1;
      reverse(a.begin() + 1, a.begin() + x + 1);
    };

    Do(post);
    Do(post1 - 1);
    Do(t);
    Do(post);
    Do(t);
  }
  cout << res.size() << '\n';
  for (auto u : res) {
    cout << u << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}