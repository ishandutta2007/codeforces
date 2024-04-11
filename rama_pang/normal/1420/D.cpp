#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  const int MOD = 998244353;

  int n, k;
  cin >> n >> k;

  vector<int> inverse(n + 1);
  inverse[1] = 1;
  for (int i = 2; i <= n; i++) {
    inverse[i] = (MOD - 1ll * (MOD / i) * inverse[MOD % i] % MOD) % MOD;
  }

  vector<int> fact(n + 1);
  vector<int> invf(n + 1);
  fact[0] = 1;
  invf[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = 1ll * i * fact[i - 1] % MOD;
    invf[i] = 1ll * inverse[i] * invf[i - 1] % MOD;
  }

  const auto C = [&](int a, int b) {
    if (b < 0 || b > a) return 0ll;
    return 1ll * fact[a] * invf[b] % MOD * invf[a - b] % MOD;
  };

  vector<pair<int, int>> events;
  events.emplace_back(0, 0);
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    events.emplace_back(l, +1);
    events.emplace_back(r + 1, -1);
  }
  sort(begin(events), end(events));

  int ans = 0;
  int cur = 0;
  for (int i = 1; i < (int) events.size(); i++) {
    int j = i;
    while (j + 1 < (int) events.size() && events[j + 1].first == events[i].first) {
      j += 1;
    }
    int add = 0;
    int sub = 0;
    for (int k = i; k <= j; k++) {
      if (events[k].second > 0) {
        add += 1;
      } else {
        sub += 1;
      }
    }
    ans += 1ll * C(cur + add - sub, k) % MOD;
    if (ans >= MOD) {
      ans -= MOD;
    }
    ans -= 1ll * C(cur - sub, k) % MOD;
    if (ans < 0) {
      ans += MOD;
    }
    cur += add - sub;
    i = j;
  }
  cout << ans << "\n";
  return 0;
}