#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  ll k;
  cin >> k;
  ll ans = -1e18;
  vector<ll> a(n);
  for (ll &x : a) {
    cin >> x;
  }
  for (ll i = n - 1; i >= 0; i--) {
    for (ll j = n - 1; j > i; j--) {
      if ((i + 1) * (j + 1) < ans) {
        break;
      }
      ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
    }
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