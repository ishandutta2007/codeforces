#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int Power(int n, int x) {
  int mul = n;
  int res = 1;
  while (x > 0) {
    if (x & 1) res = 1ll * res * mul % MOD;
    mul = 1ll * mul * mul % MOD;
    x /= 2;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n + 1), pref(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(begin(a) + 1, end(a), greater<int>());
  for (int i = 1; i <= n; i++) {
    pref[i] = (a[i] + pref[i - 1]) % MOD;
  }
  vector<int> ans;
  for (int k = 1; k <= n; k++) {
    int res = 0;
    for (int i = 0, j = 0; i <= n; i += k, j++) {
      res = (res + (1ll * j * ((pref[min(i + k, n)] - pref[i]) % MOD) % MOD)) % MOD;
    }
    ans.emplace_back(1ll * res * Power(n, MOD - 2) % MOD);
  }

  for (auto i : ans) {
    if (i < 0) i += MOD;
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}