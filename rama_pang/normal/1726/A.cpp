#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, a[i] - a[(i + 1) % n]);
    ans = max(ans, a[i] - a[0]);
    ans = max(ans, a[n - 1] - a[i]);
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