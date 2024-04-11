#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >>  i;

  const auto Check = [&](int x) {
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) {
      b[i] = (a[i] < x ? -1 : 1);
      c[i] = b[i];
      if (i) c[i] += c[i - 1];
    }
    int sum = c[k - 1];
    int mx = sum;
    int minim = 0;
    for (int i = k - 1; i < n; i++) {
      mx = max(mx, sum - minim);
      minim = min(minim, c[i - k + 1]);
      if (i + 1 < n) sum += b[i + 1];
    }
    return mx >= 1;
  };

  int lo = 1, hi = n;
  while (lo < hi) {
    int md = (lo + hi + 1) / 2;
    if (Check(md)) {
      lo = md;
    } else {
      hi = md - 1;
    }
  }
  cout << lo << '\n';
  return 0;
}