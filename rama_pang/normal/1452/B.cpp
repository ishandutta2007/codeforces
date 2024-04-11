#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long ans = 0;
  int mx = *max_element(begin(a), end(a));
  long long lim = (sum + n - 2) / (n - 1);
  ans += ((n - 1) - (sum % (n - 1))) % (n - 1);
  if (mx > lim) {
    ans += 1ll * (mx - lim) * (n - 1);
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}