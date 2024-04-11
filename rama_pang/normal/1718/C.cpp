#include <bits/stdc++.h>
using namespace std;

using lint = long long;

const lint MOD = 1e9 + 7;
const lint INF = 1e18;

void Main() {
  int n, q;
  cin >> n >> q;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<lint> qp(q), qx(q);
  for (int i = 0; i < q; i++) {
    cin >> qp[i] >> qx[i];
    qp[i]--;
  }
  // gcd(n, k) different cycles
  // iterate sqrt factors of n
  // wait, but cycleSize = n / g, so it must be same
  vector<lint> GCD;
  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      GCD.emplace_back(i);
    }
  }
  vector<lint> ans(q + 1);
  for (auto g : GCD) {
    auto b = a;
    vector<lint> sum(2 * g);
    for (int i = 0; i < n; i++) {
      sum[g + i % g] += 1ll * a[i] * g;
    }
    for (int i = g - 1; i >= 0; i--) {
      sum[i] = max(sum[i * 2], sum[i * 2 + 1]);
    }
    const auto Assign = [&](int p, int x) {
      sum[g + p % g] += 1ll * (x - a[p]) * g;
      a[p] = x;
      p = p % g + g;
      for (p /= 2; p > 0; p /= 2) {
        sum[p] = max(sum[p * 2], sum[p * 2 + 1]);
      }
    };
    const auto Query = [&](int l, int r) {
      lint z = 0;
      for (l += g, r += g; l < r; l /= 2, r /= 2) {
        if (l & 1) z = max(z, sum[l++]);
        if (r & 1) z = max(z, sum[--r]);
      }
      return z;
    };
    ans[0] = max(ans[0], Query(0, g));
    for (int i = 0; i < q; i++) {
      Assign(qp[i], qx[i]);
      ans[i + 1] = max(ans[i + 1], Query(0, g));
    }
    a = b;
  }
  for (int i = 0; i <= q; i++) {
    cout << ans[i] << '\n';
  }
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