#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  long long res = 0;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    res += 1ll * i * a[i] - sum;
    if (i > 1) res -= a[i] - a[i - 1];
  }
  cout << -res << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) {
    solve(test);
  }
  return 0;
}