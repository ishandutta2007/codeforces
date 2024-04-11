#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  long long sum = 0;
  long long num_odd = 0;
  for (int i = 1; i + 1 < n; i++) {
    sum += a[i];
    num_odd += (a[i] % 2);
  }
  if (n == 3 && a[1] % 2) {
    cout << -1 << '\n';
    return;
  }
  if (num_odd == sum) {
    cout << -1 << '\n';
    return;
  }
  cout << (sum + num_odd) / 2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}