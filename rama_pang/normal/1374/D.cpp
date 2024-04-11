#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
      i %= k;
      if (i > 0) {
        i = k - i;
      }
    }
    map<int, int> cnt;
    pair<int, int> mx = {0, 0};
    for (int i = 0; i < n; i++) {
      if (a[i] != 0) {
        cnt[a[i]]++;
        mx = max(mx, {cnt[a[i]], a[i]});
      }
    }
    lint ans = 1ll * (mx.first - 1) * k + (mx.second + 1);
    cout << max(ans, 0ll) << "\n";
  }
}