#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

lint Power(lint n, lint x) {
  lint res = 1;
  for (; x > 0; x /= 2, n = 1ll * n * n % MOD) {
    if (x & 1) {
      res = 1ll * res * n % MOD;
    }
  }
  return res;
}

void Main() {
  int n;
  cin >> n;
  vector<lint> a(n);
  for (auto &i : a) cin >> i;
  for (int i = 1; i < n; i++) {
    a[i] -= a[0];
  }
  for (int i = n - 1; i > 1; i--) {
    a[i] -= a[i - 1];
  }
  a.erase(begin(a));
  n--;
  lint ans = 1e18;
  lint tot = 0;
  for (int i = 0; i < n; i++) {
    tot += abs(a[i]);
  }
  ans = min(ans, tot - abs(a.back()));
  for (int i = 0; i + 1 < n; i++) {
    if (a[i] <= 0 && a[i + 1] <= 0) {
      continue;
    }
    if (a[i] >= 0 && a[i + 1] >= 0) {
      continue;
    }
    lint nw = min(abs(a[i]), abs(a[i + 1]));
    ans = min(ans, tot - 2 * nw);
  }
  ans = min(ans, tot - abs(a.front()));
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}