#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  if (n > m) {
    cout << 0 << '\n';
    return;
  }
  // n <= m !
  int x = m - n + 1;
  int q = 60;
  while (q >= 0 and (!((1LL << q) & n) or !((1LL << q) & x))) {
    --q;
  }
  if (q == -1) {
    cout << x << '\n';
    return;
  }
  while (((1LL << q) & x) or ((1LL << q) & n))
    q++;
  x |= 1LL << q;
  for (int p = 0; p < q; ++p)
    if ((1LL << p) & x)
      x ^= (1LL << p);
  assert(!(x & n));
  cout << x << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}