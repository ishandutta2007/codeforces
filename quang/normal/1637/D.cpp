#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  vector<int> b(n);
  for (auto &u : b) {
    cin >> u;
  }
  const int MAX = 100 * 100;
  const long long INF = 1e18;
  vector<vector<long long>> f(n + 1, vector<long long>(MAX + 1, INF));
  f[0][0] = 0;
  long long tot = 0;
  for (int i = 0; i < n; i++) {
    for (int sum = 0; sum <= MAX; sum ++) {
      if (f[i][sum] >= INF) continue;
      if (sum + a[i] <= MAX) {
        f[i + 1][sum + a[i]] = min(f[i + 1][sum + a[i]], f[i][sum] + 1ll * a[i] * sum + 1ll * b[i] * (tot - sum));
      }
      if (sum + b[i] <= MAX) {
        f[i + 1][sum + b[i]] = min(f[i + 1][sum + b[i]], f[i][sum] + 1ll * b[i] * sum + 1ll * a[i] * (tot - sum)); 
      }
    }
    tot += a[i] + b[i];
  }
  long long res = 0;
  for (auto &u : a) res += 1ll * u * u;
  for (auto &u : b) res += 1ll * u * u;
  long long min_val = INF;
  for (int i = 0; i <= MAX; i++) {
    min_val = min(min_val, f[n][i]);
  }
  cout << res * (n - 1) + 2ll * min_val << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}