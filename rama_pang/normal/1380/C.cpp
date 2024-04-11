#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(begin(a), end(a));
    reverse(begin(a), end(a));
    int cnt = 0;
    for (auto i : a) {
      cnt++;
      if (1ll * i * cnt >= x) {
        ans++;
        cnt = 0;
      }
    }
    cout << ans << "\n";
  }
}