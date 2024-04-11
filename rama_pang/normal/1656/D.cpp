#include <bits/stdc++.h>
using namespace std;

int Check(long long n) {
  for (int k = 2; true; k++) {
    if (1ll * k * (k + 1) / 2 <= n) {
      long long d = n;
      d -= 1ll * k * (k - 1) / 2;
      if (d % k == 0) return k;
    } else {
      break;
    }
  }
  return -1;
}

void Main() {
  long long n;
  cin >> n;

  if (__builtin_popcountll(n) == 1) {
    cout << "-1\n";
    return;
  }
  for (long long k = 2; true; k *= 2) {
    int ok = 0;
    if (1ll * k * (k + 1) / 2 <= n) {
      ok = 1;
      long long d = n;
      d -= 1ll * k * (k - 1) / 2;
      if (d % k == 0) {
        cout << k << '\n';
        return;
      }
    }
    if (n % k == 0) {
      k = n / k;
      if (1ll * k * (k + 1) / 2 <= n) {
        ok = 1;
        long long d = n;
        d -= 1ll * k * (k - 1) / 2;
        if (d % k == 0) {
          cout << k << '\n';
          return;
        }
      }
      k = n / k;
    }
    if (!ok) break;
  }
  return;
  long long ans = 2;
  while (true) {
  }
  long long x = n;
  while (x % 2 == 0) {
    x /= 2;
    ans *= 2;
  }
  cout << ans << '\n';
  assert(ans * (ans + 1) / 2 <= n);
  n -= ans * (ans + 1) / 2;
  assert(n % ans == 0);
  cout << ans << '\n';
  // assert()

  // cout << '\n';
  // cout << Check(n) << '\n';
  // pair<int, int> mx = {-1, -1};
  // for (int i = 1; i <= n; i++) {
  //   mx = max(mx, {Check(i), i});
  // }
  // cout << mx.first << ' ' << mx.second << '\n';
  // cout << Check(n) << '\n';

  // n - (0 + 1 + 2 + ... + k - 1) is divisible by k
  // n - k * (k - 1) / 2 is divisible by k
  // n - k * (k - 1) / 2 = pk for some p
  //
  // if k is even:
  // k = 2q for some q >= 1
  // n - 2q * (2q - 1)/2 = 2pq
  // n - q(2q - 1) = 2pq
  // n mod q = 0
  //
  // n = 2pq + 2q^2 - 1
  //
  // if k is odd
  // k = 2q + 1 for q >= 1
  // n - (2q + 1)q = p(2q + 1)
  // n mod (2q + 1) = 0
  //
  // n = (2q + 1)(p + q)
  //
  //
  // n - 2q^2 - q = 2pq + p
  //

  // n = pk + k(k - 1) / 2 for some p
  // 2n = 2pk + k(k - 1) for some p
  // 2n = 2pk + k^2 - k for some p
  // k^2 + (2p - 1)k - 2n = 0 for some p
  // k = (1 - 2p) +- sqrt((2p - 1)^2 + 8n) / 2
  //
  // We want:
  // (1 - 2p) + sqrt((2p - 1)^2 + 8n) to be divisible by 2
  // sqrt((2p - 1)^2 + 8n) mod 2 = 1
  // q^2 = (2p - 1)^2 + 8n
  // q^2 - (2p - 1)^2 = 8n
  // (q + 2p - 1)(q - 2p + 1) = 8n
  // q must be odd
  // q + 2p - 1 = 8
  // q - 2p + 1 = n
  // 2q = 8+n
  // q = (8 + n) / 2
  // p = (8 - q + 1)/2
  //

  // k = 2: can divide multiple of 2
  // k = 3: can divide multiple of 3
  //
  // other requirement:n must be at least 1 + 2 + ... + k = k(k + 1)/2
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