#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int a[N];
long long s[N];

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (i & 1) s[i] = s[i - 1] + a[i];
    else s[i] = s[i - 1] - a[i];
  }

  long long res = 0;
  for (int i = 1; i <= n; i += 2) {
    long long min_val = 1e18;
    for (int j = i + 1; j <= n; j += 2) {

      long long low = max(s[i - 1], s[j]);
      long long high = min(s[i] - 1, s[j - 1] - 1);
      high = min(high, min_val);
      // cout << i << ' ' << j << ' ' << min_val << ' ' << low << ' ' << high << endl;
      res += max(0ll, high - low + 1);
      min_val = min(min_val, s[j]);
    }
  }
  cout << res << '\n';
  return 0;
}