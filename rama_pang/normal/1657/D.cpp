#include <bits/stdc++.h>
using namespace std;

void Main() {
  // mH / uD < uH / mD
  // mH * mD < uH * uD
  // if we buy x monsters, then
  // mH * mD < uH * uD * x
  int n, C;
  cin >> n >> C;
  vector<long long> mx(C + 1);
  vector<int> c(n), d(n), h(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> d[i] >> h[i];
    mx[c[i]] = max(mx[c[i]], 1ll * d[i] * h[i]);
  }
  for (int i = 1; i < C + 1; i++) {
    for (int j = i; j < C + 1; j += i) {
      mx[j] = max(mx[j], (j / i) * mx[i]);
    }
  }
  for (int i = 1; i <= C; i++) {
    mx[i] = max(mx[i], mx[i - 1]);
  }
  int q;
  cin >> q;
  while (q--) {
    long long u, v;
    cin >> u >> v;
    int lo = 0, hi = C + 1;
    while (lo < hi) {
      int md = (lo + hi) / 2;
      if (u * v < mx[md]) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }
    cout << (lo > C ? -1 : lo) << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}