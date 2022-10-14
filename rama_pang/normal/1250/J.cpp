#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m, h;
  cin >> n >> m >> h;
  h--;
  n--;
  vector<int> a(m);
  int other = 0;
  int me = 0;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    if (i == h) {
      a[i]--;
      me += a[i];
    } else {
      other += a[i];
    }
  }
  if (other + me < n) {
    cout << -1 << "\n";
    return 0;
  }
  auto Choose = [&](int n, int k) -> double {
    double res = 1;
    for (int i = 0; i < k; i++) {
      res *= n - i;
      res /= i + 1;
    }
    return res;
  };
  double ans = 1;
  ans -= Choose(other, n) / Choose(other + me, n);
  cout << fixed << setprecision(20) << ans << "\n";
  return 0;
}