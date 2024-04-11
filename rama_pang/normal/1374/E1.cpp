#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a, b, both;
  for (int i = 0; i < n; i++) {
    int t, l, r;
    cin >> t >> l >> r;
    if (l == 1 && r == 1) {
      both.emplace_back(t);
    } else if (l == 1) {
      a.emplace_back(t);
    } else if (r == 1) {
      b.emplace_back(t);
    }
  }  
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  sort(begin(both), end(both));
  for (int i = 1; i < (int) a.size(); i++) {
    a[i] += a[i - 1];
  }
  for (int i = 1; i < (int) b.size(); i++) {
    b[i] += b[i - 1];
  }
  for (int i = 1; i < (int) both.size(); i++) {
    both[i] += both[i - 1];
  }
  int ans = 2e9;
  if (both.size() + a.size() < k || both.size() + b.size() < k) {
    cout << -1 << "\n";
    return 0;
  }
  for (int d = 0; d <= (int) both.size(); d++) {
    int need = k - d;
    if (need > a.size() || need > b.size()) {
      continue;
    }
    if (need <= 0) {
      ans = min(ans, (d > 0 ? both[d - 1] : 0));
      continue;
    }
    ans = min(ans, (d > 0 ? both[d - 1] : 0) + a[need - 1] + b[need - 1]);
  }
  cout << ans << "\n";
}