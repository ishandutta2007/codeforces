#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m, k;
  lint ta, tb;
  cin >> n >> m >> ta >> tb >> k;
  vector<lint> a(n);
  vector<lint> b(m);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  
  if (k >= n) {
    cout << -1 << "\n";
    return 0;
  }

  lint ans = -1;
  for (int ca = 0; ca <= k; ca++) {
    int cb = k - ca;
    int go = lower_bound(begin(b), end(b), a[ca] + ta) - begin(b);
    go += cb;
    if (go >= m) {
      cout << -1 << "\n";
      return 0;
    }
    ans = max(ans, b[go] + tb);
  }
  cout << ans << "\n";
  return 0;
}