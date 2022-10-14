#include "bits/stdc++.h"
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (x).size()

using lint = long long;

const lint MOD = 998244353;

lint fact[400005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  fact[0] = 1;
  for (int i = 1; i < 400005; i++) {
    fact[i] = i * fact[i - 1] % MOD;
  }

  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  for (auto &i : p) {
    cin >> i;
  }

  lint mx = 0;
  lint cur = n;
  for (int i = 0; i < k; i++) {
    mx += cur;
    cur--;
  }
  int lim = n - k;

  lint ans = 1;
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (p[i] > lim) {
      if (last == -1) {
        last = i;
        continue;
      }
      ans *= i - last;
      ans %= MOD;
      last = i;
    }
  }
  cout << mx << " " << ans << "\n";


}