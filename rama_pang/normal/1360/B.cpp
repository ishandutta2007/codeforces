#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(begin(a), end(a));
    int ans = 1e9;
    for (int i = 0; i + 1 < n; i++) {
      ans = min(ans, a[i + 1] - a[i]);
    }
    cout << ans << "\n";
  }
}