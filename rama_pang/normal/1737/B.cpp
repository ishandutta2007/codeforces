#include <bits/stdc++.h>
using namespace std;

void Main() {
  long long l, r;
  cin >> l >> r;
  // x = a^2 okay
  // x = a^2 + c
  // x < a^2 + 2a + 1
  // c mod a = 0
  // 0 <= c <= 2a
  // c = 0 or c = a or c = 2a
  // a^2 or a^2 + a
  // 1, 2, 3, 4, 6, 8, 9, 12, 15,
  const auto Solve = [&](long long X, int c) {
    long long ret = 0;
    long long lo = 0, hi = 2e9;
    while (lo < hi) {
      long long md = (lo + hi + 1) / 2;
      if (1ll * md * md + c * md <= X) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }
    return lo;
  };
  long long ans = 0;
  ans += Solve(r, 0);
  ans += Solve(r, 1);
  ans += Solve(r, 2);
  ans -= Solve(l - 1, 0);
  ans -= Solve(l - 1, 1);
  ans -= Solve(l - 1, 2);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T =1 ;
  cin >> T;
  while (T--) Main();
}