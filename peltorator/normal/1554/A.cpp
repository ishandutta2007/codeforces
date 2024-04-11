#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  ll last = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ans = max(ans, x * last);
    last = x;
  }
  cout << ans << '\n';
}

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }
}