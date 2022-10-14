#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int g = 0;
    vector<int> ans(n);
    vector<int> done(n);
    for (int i = 0; i < n; i++) {
      int pos = -1;
      for (int j = 0; j < n; j++) if (!done[j]) {
        if (pos == -1 || __gcd(g, a[j]) > __gcd(g, a[pos])) {
          pos = j;
        }
      }
      done[pos] = 1;
      ans[i] = a[pos];
      g = __gcd(g, a[pos]);
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " \n"[i + 1 == n];
    }
  }
  return 0;
}