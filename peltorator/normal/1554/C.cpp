#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n, m;
  cin >> n >> m;
  if (m < n) {
    cout << "0\n";
    return;
  }
  ll ans = 0;
  bool ok = false;
  ll first = -1;
  for (ll x = 32; x >= 0; x--) {
    ll a = ((n >> x) & 1LL);
    ll b = ((m >> x) & 1LL);
    if (a > b) {
      ok = true;
      break;
    } else if (b > a) {
      if (first == -1) {
        first = x;
      }
      ans |= (1LL << x);
    }
  }
  if (!ok) {
    first = 0;
    while (((m >> first) & 1LL) == 1) {
      first++;
    }
    ans >>= first;
    ans |= 1LL;
    ans <<= first;
    //ans |= (1LL << first);
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