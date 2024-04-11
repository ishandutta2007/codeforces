#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector <ll> a(n), d(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> d[i];
  if (k == 0) {
    ll ans = 0;
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
      sum += a[i];
      ans = max(ans, sum - d[i]);
    }
    cout << ans;
    return 0;
  }
  if (k >= 2) {
    ll ans = 0;
    ll sum = 0;
    ll mi = INF;
    for (int i = n - 1; i >= 0; i--) {
      sum += a[i];
      ans = max(ans, sum - d[i]);
      if (i != n - 1)
        mi = min(d[i], mi);
    }
    ans = max(ans, sum - mi);
    ans = max(ans, a[n - 1] - d[n - 1]);
    cout << ans;
    return 0;
  }
  vector <ll> suf(n);
  ll sum = 0, mi = INF;
  ll ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    sum += a[i];
    mi = min(mi, d[i]);
    suf[i] = max(0ll, sum - d[i]);
    if (i >= 1)
      ans = max(ans, suf[i]);
  }
  for (int i = n - 2; i >= 0; i--)
    suf[i] = max(suf[i], suf[i + 1]);
  mi = d[0], sum = a[0];
  for (int i = 1; i + 1 < n; i++) {
    mi = min(mi, d[i]);
    sum += a[i];
    ans = max(ans, sum - mi + suf[i + 1]);
  }
  {
    ll nsum = 0, nans = 0;
    for (int i = 0; i < n; i++)
      nsum += a[i];
    for (int i = 1; i + 1 < n; i++)
      nans = max(nans, -d[0] + nsum - a[i] + max(0ll, a[i] - d[i]));
    ans = max(ans, nans);
  }
  cout << ans;
  return 0;
}