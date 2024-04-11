#include <bits/stdc++.h>
using namespace std;

void Main() {
  long long k, x;
  cin >> k >> x;
  const auto Calc = [&](long long lines) {
    long long res = 0;
    if (lines <= k) {
      res += 1ll * lines * (lines + 1) / 2;
    } else {
      lines -= k;
      res += 1ll * k * (k + 1) / 2;
      res += 1ll * (k - 1 + k - lines) * lines / 2;
    }
    return res;
  };
  long long lo = 0, hi = k + k - 1;
  while (lo < hi) {
    long long md = (lo + hi) / 2;
    if (Calc(md) >= x) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  cout << lo << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }  
}